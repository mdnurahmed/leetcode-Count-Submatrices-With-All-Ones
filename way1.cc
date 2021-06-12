class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        if (mat.size() == 0)
            return 0;
        vector<vector<int>> height;
        height.resize(mat.size() + 2, vector<int>(mat[0].size() + 2));
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                height[i][j] = mat[i][j];
                if (i > 0 && mat[i][j])
                {
                    height[i][j] += height[i - 1][j];
                }
                int min_height = INT_MAX;
                for (int k = j; k >= 0 && min_height; k--)
                {
                    min_height = min(min_height, height[i][k]);
                    cnt += min_height;
                }
            }
        }
        return cnt;
    }
};