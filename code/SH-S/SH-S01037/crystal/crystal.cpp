#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
const int MAXN=500000;
int a[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[n];
	sort(a+1,a+n+1);
	int b[n];
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+i;
		int k=m*n/(a[n]-a[n-1]);
		if(k<b[i])
			if(k>=b[i-1])
				ans=i;			
	}
	cout<<ans;
	return 0;	
}
