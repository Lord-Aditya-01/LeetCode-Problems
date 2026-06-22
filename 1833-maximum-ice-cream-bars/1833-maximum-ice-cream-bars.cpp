class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxIndex = *max_element(costs.begin(), costs.end());
        vector<int> cs(maxIndex + 1);
        for(int i = 0 ; i < costs.size() ; ++i) ++cs[costs[i]];
        int totalBars = 0;
        for(int cost = 1 ; cost <= maxIndex ; ++cost) {
            if(cs[cost] > 0) {
                int canBuy = min(cs[cost], coins / cost);
                totalBars += canBuy;
                coins -= canBuy * cost;
                if(coins == 0) break;
            }
        }
        return totalBars;
    }
};