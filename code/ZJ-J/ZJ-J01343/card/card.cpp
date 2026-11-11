#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;ll a[500500];
ll v[500500];
ll f[500500];
ll s[300300];
ll r;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(int)*n);
		memset(f,0,sizeof(int)*n);
		r=0;
		for(int j=i;j<=n;j++){
			if(!v[a[j]]||v[a[j]]>r||(f[v[a[j]]]!=a[j]))v[a[j]]=++r,f[r]=a[j];
			else r=v[a[j]];
		}
		for(int j=1;j<=r;j++){
			s[f[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
}
