#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],c[300005],cnt=0,q[500005],top=0;
ll f(ll x){
	for(ll i=1;i<=top;i++){
		if(q[i]==x) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		top=1;
		memset(q,0,sizeof(q));
		for(ll j=i;j<=n;j++){
			ll x=a[j];
			if(f(x)!=0){
				top=f(x);
			}else{
				top++;
				q[top]=a[j];
				
			}
		}
		for(ll j=1;j<=top;j++){
			c[q[j]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
