#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],l,big;
ll ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	
	for(int i=2;i<=n;++i){
		ans+=(a[i]-a[i-1])*(i-l);
		while(ans>m){
			ans-=a[i]-a[l];
			l++;
		}
		big=max(big,i-l+1);
	}
	
	cout<<big<<"\n";
	
	return 0;
}