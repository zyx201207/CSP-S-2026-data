#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll a[maxn];
ll n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((a[i]&a[i+1])>ans) ans=(a[i]&a[i+1]);
		}
	}
	cout<<ans<<'\n';
}
