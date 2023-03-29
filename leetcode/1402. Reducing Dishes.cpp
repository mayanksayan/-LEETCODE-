class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        bool allPos = true, allNeg = true;
        for(int s : satisfaction){
            if(s > 0) allNeg = false;
            if(s < 0) allPos = false;
            if(!allPos && !allNeg) break;
        }
        if(allNeg) return 0;
        
        int ltc = 0;
        
        sort(satisfaction.begin(), satisfaction.end());
        for(int i = 0; i < satisfaction.size(); i++){
            // cout << i << " " << satisfaction[i] << endl;
            ltc += (i+1) * satisfaction[i];
        }
        
        if(allPos){
            return ltc;
        }
        
        // cout << "ltc: " << ltc << endl;
        
        //part neg, part pos
        int ans = 0;
        int sum = accumulate(satisfaction.begin(), satisfaction.end(), 0);
        for(int i = 0; i < satisfaction.size(); i++){
            if(i > 0){
                //update ltc
                ltc -= sum;
                sum -= satisfaction[i-1];
            }
            // cout << ltc << " " << sum << endl;
            ans = max(ans, ltc);
        }
        
        return ans;
    }
};

