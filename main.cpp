#include "priorityQ.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << fixed << setprecision(2); // format all float outputs to 2 decimal places

    if (argc != 5) return 1; // exit if incorrect number of arguments

    ifstream stockInput(argv[1]); // file containing stock names
    ifstream priceInput(argv[2]); // file containing price updates
    int totalDays = stoi(argv[3]); // number of simulation days
    double availableFunds = stod(argv[4]); // starting funds

    priorityQ<string, double> stockQueue; // min-heap of stocks by price
    unordered_map<string, double> purchasedStocks; // tracks what was bought and at what price

    string stockName;
    while (stockInput >> stockName) {
        stockQueue.push_back(stockName, 0.0); // initialize with 0.0 price
    }

	// Starts with the first day, loop breaks if there are exceeds the amount of simulated days or no more funds
    for (int currentDay = 1; currentDay <= totalDays + 1 && availableFunds > 0; ++currentDay)
    {
        cout << "Day " << currentDay << endl;

        unordered_map<string, double> todayPrices; // current day's price map

        // Read and update today's stock prices 
        string line;
        while (getline(priceInput, line)) {
            if (line.empty()) {
				break; // blank line = end of day's data
			}

			// Each line of the file is divided into two variables:
            istringstream ss(line);
            string stock; // the stock name
            double newPrice; // and its price
            ss >> stock >> newPrice; 
            todayPrices[stock] = newPrice; // price of the stock on an nth day

            // Only calculate gain/loss if we bought this stock yesterday
            if (purchasedStocks.find(stock) != purchasedStocks.end()) {
                double oldPrice = purchasedStocks[stock]; // Keeps track of the old price of stock (temp variable)

				// Compares the oldPrice of the previous purchased stock and the newPrice of the current purchased stock 
                if (newPrice > oldPrice) {
                    cout << "Stock " << stock << " went up in value by $ " << (newPrice - oldPrice) << " per share" << endl;
                    availableFunds += (newPrice - oldPrice); // adding because it went up in value
                } else if (oldPrice > newPrice) {
                    cout << "Stock " << stock << " went down in value by $ " << (oldPrice - newPrice) << " per share" << endl;
                    availableFunds -= (oldPrice - newPrice); // adding because it went down in value
                }
				stockQueue.push_back(stock, newPrice); 
            }
			else {
				stockQueue.update(stock, newPrice);
			}
        }

        // Stop before buying on the final day 
        if (currentDay == totalDays + 1) {
			break;
		}
        cout << "\nCurrent funds $ " << availableFunds << endl;

        // Buy cheapest stocks until 25% of current funds is spent 
        double amountSpent = 0.0; // default, used for to compare to the spending limit
        double spendingLimit = 0.25 * availableFunds; // spending limit should be no more than 25% spending limit (ex. if $500 available, you can spend no more than $125)
        purchasedStocks.clear(); // reset for today's purchases

		// Buying stocks is done if queue is empty or amount spent is more than spending limit
        while (!stockQueue.isEmpty() && amountSpent < spendingLimit) {
            string cheapest = stockQueue.getRootKey(); 
            double price = stockQueue.getRootPriority();
            if (price > availableFunds) {
				break;
			}

            cout << "Stock " << cheapest << " Bought at $ " << price << " per share" << endl;

            stockQueue.pop_front(); // remove from queue
            amountSpent += price; // price of each stock is cumulatively added to a variable
            purchasedStocks[cheapest] = price; // record purchase
        }

        cout << "\n\n";
    }

	// Outputs after the final day of simulation
    cout << "\nFinal funds $ " << availableFunds << endl;
    return 0;


}
