#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long

ll n,unq,cur,ans,m,w;
ll a[N],v[N],c[N];
set<ll>s;
map<ll,ll>mp;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		s.insert(a[i]);
	}
	for(auto x:s){
		mp[x]=++unq;
		v[unq]=x;	
	}
	for(int i=1;i<=n;++i)++c[mp[a[i]]];
	for(int i=1,j=1;i<=unq;++i){
		w+=(v[i]-v[i-1])*cur;
		cur+=c[i];
		while(w>m&&i>j){
			ll nd=(w-m+v[i]-v[j]-1)/(v[i]-v[j]);
			nd=min(nd,c[j]);
			w-=(v[i]-v[j])*nd;
			cur-=nd;
			c[j]-=nd;
			if(c[j]==0)++j;
		}
		if(w<=m)ans=max(ans,cur);
	}
	printf("%lld",ans);
	
	return 0;
}
