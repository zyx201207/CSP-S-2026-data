#include<bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
long long n,m;
long long a[600000];
long long sum[600000];
long long maxn=-1e7;
int main()
{
	IOS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(m>1e8)
        {
            sum[i]=sum[i-1]+a[i];
            if(sum[i]>m){cout<<i;break;}
            else if(sum[i]==m){cout<<i+1;break;}
        }
    }
    if(m>1e8)return 0;
    for(int i=1;i<=n;i++)
    {
        long long x=1;
        for(int j=0;j<=m;j++)
        {
            for(int k=1;k<i;k++)
            {
                if(a[i]-a[k]==j)x++;
            }
        }
        maxn=max(maxn,x);
    }
    cout<<maxn;
	return 0;
}

