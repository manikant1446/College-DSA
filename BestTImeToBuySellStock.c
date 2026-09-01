int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {

        // Minimum buying price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Current profit
        int profit = prices[i] - minPrice;

        // Maximum profit
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}