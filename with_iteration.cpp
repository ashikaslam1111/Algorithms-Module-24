#include<bits/stdc++.h>
using namespace std;
const int wight =1e5+5;
const int item  =105;
long long dp[item][wight];
int value[item];
int weight[item];
int main()
{
    int n;
    int w;
    cin>>n>>w;
    for(int i =1; i<=n; i++)
        cin>>weight[i]>>value[i];
    for(int i =1; i<=n; i++)
    {
        for(int j = 0; j<=w; j++)
        {
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(value[i]+dp[i-1][j-weight[i]],dp[i-1][j]);
        }
    }
    cout<<dp[n][w];
    return 0;
}
