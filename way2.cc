class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        if (mat.size() == 0)
            return 0;
        vector<vector<int>> height;
        vector<int> dp, left;
        height.resize(mat.size() + 2, vector<int>(mat[0].size() + 2));
        dp.resize(mat[0].size() + 2);
        left.resize(mat[0].size() + 2);
        stack<int> st;
        int cnt = 0, pre = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                height[i][j] = mat[i][j];
                if (i > 0 && mat[i][j])
                {
                    height[i][j] += height[i - 1][j];
                }
            }
            for (int j = 0; j < mat[0].size(); j++)
                dp[j] = left[j] = 0;

            for (int j = mat[0].size() - 1; j >= 0; j--)
            {
                while (!st.empty() && height[i][st.top()] > height[i][j])
                {
                    left[st.top()] = j + 1;
                    st.pop();
                }
                st.push(j);
            }
            while (!st.empty())
            {
                left[st.top()] = 0;
                st.pop();
            }
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (left[j] > 0)
                    pre = dp[left[j] - 1];
                else
                    pre = 0;
                dp[j] = pre + (j - left[j] + 1) * height[i][j];
                cnt += dp[j];
            }
        }
        return cnt;
    }
};