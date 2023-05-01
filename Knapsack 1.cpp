#include<bits/stdc++.h>
using namespace std;
const int wight =1e5+5;
const int item  =105;
long long dp[item][wight];
int value[item];
int weight[item];
long long solv(int n,int cap)
{
    if(n == 0)return 0;
    if(dp[n][cap] != -1)return dp[n][cap];
    if(cap<weight[n])
    {
        dp[n][cap] = solv(n-1,cap);
        return dp[n][cap];
    }
    long long ans1  = value[n] +  solv(n-1,cap-weight[n]);
    long long ans2  = solv(n-1,cap);
    dp[n][cap] = max(ans1,ans2);
    return dp[n][cap];
}
int main()
{
    int n;
    int w;
    cin>>n>>w;
    for(int i =1; i<=n; i++)
        cin>>weight[i]>>value[i];
    for( int i =1; i<=n; i++)
        for(int j=1; j<=w; j++)dp[i][j] = -1;
    cout<<solv(n,w);
    return 0;
}
