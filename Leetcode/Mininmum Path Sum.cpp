class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        
        
        vector<vector<int>> mat(row+1,vector<int>(col+1,0));
        
        mat[row][col] = grid[row][col];
        
        //edge case 1 filling rightmost column
        for(int i=row-1;i>=0;i--){
            mat[i][col] = grid[i][col] + mat[i+1][col];
        }
        


        //edge case 2 filling lowermost row
        for(int j=col-1;j>=0;j--){
            mat[row][j] = grid[row][j] + mat[row][j+1];
        }


        //filling remaining rows and columns
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                mat[i][j] = grid[i][j] + min(mat[i+1][j] , mat[i][j+1]);
            }
        }
        
        return mat[0][0];
    }
};