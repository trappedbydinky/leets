class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0, n = grid.size() ,flag = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                for(int k = 0 ; k < n ; k++)
                {
                    if(grid[i][k] != grid[k][j])
                    {
                        flag = 1; 
                        break;
                    }
                }
                if(flag == 0)
                {
                    count++;
                }
                flag = 0 ;
            }
        }
        return count ;
    }
};