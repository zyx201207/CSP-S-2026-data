#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	bool p1=1,p2=1;
	ll id=a[2]-a[1];
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1]) p1=0;
		if(a[i+1]-a[i]!=id) p2=0;
	}
	if(p1)
	{
		cout<<n;
		return 0;
	}
	if(p2)
	{
		int k=m/id;
		ll now=0;
		int bei=1;
		while(now<=k){
			now+=bei;
			bei++;
		}
		if(now>m) now-=bei;
		cout<<bei-1;
	}
	int anss=0;
	for(int i=2;i<=n;i++)
	{
		ll sum=0;
		int j;
		for(j=i-1;j>=1;j--)
		{
			sum+=(a[i]-a[j]);
			if(sum>m) break;
		}
	    anss=max(anss,i-j);
	}
	cout<<anss;
	return 0;
}
