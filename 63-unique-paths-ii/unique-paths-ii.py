class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        
        def calc(i,j):
            memo={}
            def helper(i,j):

                if i>=m or j>=n:

                    return 0

                if obstacleGrid[i][j]==1:

                    return 0

                if i==m-1 and j==n-1:

                    return 1

                if (i,j) in memo:

                    return memo[(i,j)]
                else:
                    memo[(i,j)]=helper(i+1,j)+helper(i,j+1)
                    return memo[(i,j)]
            return helper(i,j)
        return calc(0,0)