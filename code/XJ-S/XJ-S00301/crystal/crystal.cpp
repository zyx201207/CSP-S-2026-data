#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,maxn,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(j=n;j>=1;j--){
		while(a[j]==a[j+1])j--;
		ll v=0;
		for(i=j-1;i>=1;i--)
		{
			v+=a[j]-a[i];
			if(v>m)break;
		}
		maxn=max(maxn,j-i);
	}
	
	cout<<maxn<<endl;
	return 0;
}
