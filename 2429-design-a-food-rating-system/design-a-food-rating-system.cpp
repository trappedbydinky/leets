class FoodRatings {
public:
 struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };
    unordered_map<string, string> f_cmap;
    unordered_map<string, int> f_rmap;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> mpq;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            f_cmap[foods[i]] = cuisines[i];
            f_rmap[foods[i]] = ratings[i];
            mpq[cuisines[i]].push({ratings[i], foods[i]}); 
        }
    }

    void changeRating(string food, int newRating) {
        f_rmap[food] = newRating;
        mpq[f_cmap[food]].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto& pq = mpq[cuisine];
        while (!pq.empty()) {
            auto [r, f] = pq.top();
            if (f_rmap[f] != r) {
                pq.pop();
            } else {
                return f;
            }
        }
        return "";
    }
};