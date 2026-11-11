#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],ans[M],f[N],v[M],ans2[M];
bool fl=1;
unordered_map<int,int>mp;
inline void add(int x){
	while(x<=n){
		if(!v[a[x]])++ans[a[x]],v[a[x]]=1;
		if(f[x])x=f[x];
		else ++x;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1])fl=0;
		ans2[a[i]]=i;
	}
	if(fl){
		for(int i=1;i<=m;++i)cout<<ans2[i]<<" ";
		return 0;
	}
	for(int i=n;i>=1;--i){
		memset(v,0,sizeof(v));
		if(mp[a[i]])f[i]=mp[a[i]],add(f[i]);
		else add(i);
		mp[a[i]]=i;
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
