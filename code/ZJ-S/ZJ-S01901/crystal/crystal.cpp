#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010],pre[500010];
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;++i){
		pre[i]=a[i]-a[i-1];
	}
	int ans=0,i=1;
	while(true){
		if(ans+(i-1)*pre[i]<=m)
			ans+=(i-1)*pre[i];
		else break;
		++i;
	}
	cout<<i-1;
	return 0;
}
