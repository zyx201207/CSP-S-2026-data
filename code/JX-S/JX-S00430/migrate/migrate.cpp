#include<bits/stdc++.h>
using namespace std;

long long x[2000005];
long long k[2000005];
long long ans = 0;

int n,d;

void dfs(int s,int i,int st)
{
    if(st <= (x[i] - x[s]) / d + ((x[i] - x[s]) % d != 0 ? 1 : 0))k[i] ++;
    if(k[i] == 2)ans ++;
    else if(k[i] == 3)ans --;
	long long t = x[i] + d;
	int p = upper_bound(x + 1,x + n + 1,t) - x - 1;
	for(int j = i + 1;j <= p;j ++)
        dfs(s,j,st + 1);
}

int main()
{
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t --)
    {
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i ++)cin>>x[i];
		for(int i = 1;i <= n;i ++)
        {
            memset(k,0,sizeof(k));
            dfs(i,i,0);
        }
		cout<<ans<<"\n";
	}
    return 0;
}
