#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll now=0,maxs=0;
	ll di=0,f=0;
	for(int i=2;i<=n;i++){
		if(i!=1&&di==a[i]-a[i-1]);
		else{
			f=1;break;
		}
		di=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		int flag=0;ll c=1;
		for(int j=i-1;j>=0;j--){
			ll diff=a[i]-a[j];
			if(now+diff>m){
				flag=1;
				break;
			}
			now+=diff;
			c++;
		}
		if(!f&&flag){
			cout<<c;
			break;
		}
		maxs=max(c,maxs);
	}
	cout<<maxs;
	return 0;
} 
