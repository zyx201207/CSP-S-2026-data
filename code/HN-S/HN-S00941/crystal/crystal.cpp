#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=0,a[500001];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
    {
    	int sum=1,x=m;
        for(int j=i-1;j>=1;j--)
		{
			if(x-(a[i]-a[j])>=0)
			    sum++,x-=a[i]-a[j];
			else
			    break;
		}	    	
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
