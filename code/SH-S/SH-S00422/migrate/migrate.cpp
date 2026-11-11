#include<bits/stdc++.h>
using namespace std;
const long long N=5005;
long long c,t,n,d,x[N],cha[N],cnt=0;
struct Node
{

    long long road;//路线数 
    long long len;//所走的最小距离 
};
Node dp[N];


int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        cnt=0;
        memset(x,0,sizeof(x));
        memset(dp,0,sizeof(dp));
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(long long i=1;i<n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    if(dp[j].len>dp[i].len+1)
					{
						dp[j].len=dp[i].len+1;
                    	dp[j].road=dp[i].road+1;
					} 
					else if(dp[j].len==dp[i].len+1)
					{
						dp[j].road=max(dp[j].road,dp[i].road+1);
					}
					else if(dp[j].len==0) 
					{
						dp[j].len=dp[i].len+1;
                    	dp[j].road=dp[i].road+1;
					}
                    //dp[j]:到j岛屿 
                }
            }
        }
        for(long long i=1;i<=n;i++)
        {
            if(dp[i].road==2) 
			{
				cnt++;
				//cout<<"dp[i].len:"<<dp[i].len<<" i:"<<i<<endl;
				
			}
        }
        cout<<cnt<<endl;
    }
    //0 2 4 2 1 2 3 4 5 2 1 2 3 4 5:1 2
    //0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
    //0 1 5 3 -2 -1 0 1 2
    return 0;
}
