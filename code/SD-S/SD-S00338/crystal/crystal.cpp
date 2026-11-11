#include<bits/stdc++.h>
#define maxn 500010
using namespace std;
long long a[maxn],b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		b[i]=a[i]-a[i-1];
	int l=1,r=1,maxx=0;
	unsigned long long sum=0;
	while(r<=n)
	{
		if(sum<=m)
		{
			if(r<=n)
				maxx=max(maxx,r-l+1);
			r++;
			sum+=b[r]*(r-l);
		}
		else
		{
			sum-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<maxx;
	return 0;
}

