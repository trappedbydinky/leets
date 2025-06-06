class Solution {
    auto d(auto x,auto y){
        return sqrt(x*x+y*y);
    }
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double xl=0,xr=100,yl,yr,res=0;
        while(xr-xl>1e-6){
            auto x=(xl+xr)/2;
            yl=0,yr=100;
            while(yr-yl>1e-6){
                auto y=(yl+yr)/2;
                double sum=0;
                for(auto& p:positions){
                    sum+=(y-p[1])/d(x-p[0],y-p[1]);
                }
                if(sum<0) yl=y;
                else yr=y;
            }
            double sum=0;
            for(auto& p:positions){
                sum+=(x-p[0])/(d(x-p[0],yl-p[1]));
            }
            if(sum<0) xl=x;
            else xr=x;
        }
        for(auto& p:positions){
            res+=d(xl-p[0],yl-p[1]);
        }
        return res;
    }
};