#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll ans=0;

ll dfs(const ll pos,const ll k,const ll& N,const ll& M,const vector<ll>& a,vector<vector<ll>>& memo){
	if(k==M) return memo[pos][k]=-1;
	ll cnt=-1;
	for(int i=pos+1;i<=N;i++){
		cnt=max(cnt,dfs(i,k+1,N,M,a,memo)&a[i]);
	}
	return memo[pos][k]=cnt;
}

ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n=read(),m=read();
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) a[i]=read();
	a[0]=-1;
	vector<vector<ll>> memo(n+5,vector<ll>(m+5));
	cout<<dfs(0,0,n,m,a,memo);
	return 0;
}