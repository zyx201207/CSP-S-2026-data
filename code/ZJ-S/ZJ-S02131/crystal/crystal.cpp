#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=5e5+5;
ll n,k,l,r,z,s,a[_],b[_],i;
ll p(ll x,ll y){return a[y]*(y-x+1)-(b[y]-b[x-1]);}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(i=1;i<=n;i++){
		for(l=1,r=i;l<r;){
			z=(l+r)>>1;
			if(p(z,i)>k)l=z+1;
			else r=z;
		}
		s=max(s,i-l+1);
	}
	cout<<s<<'\n';
}
