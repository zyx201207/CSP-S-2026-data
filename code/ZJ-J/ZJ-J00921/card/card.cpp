#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500010],m,ans;
ll f[300010],r,b[500010];
ll sc[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		r=i-1;
		ans=0;
		for(ll j=i;j<=n;j++){
			if(f[a[j]]!=0){
				ll rr=r;
				r=f[a[j]]-1;
				for(ll k=f[a[j]];k<=rr;k++){
					f[b[k]]=0;
				}
			}
			b[++r]=a[j];
			f[a[j]]=r;
		}
		for(ll j=1;j<=m;j++){
			if(f[j]!=0)sc[j]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<sc[i]<<" ";
	}
}
