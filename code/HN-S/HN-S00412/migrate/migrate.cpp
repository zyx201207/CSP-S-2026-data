#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,pre[N],nxt[N],s[N],f[N],fg[N];
ll ans,z[N],m;
queue<int>q;
void bfs(int d){
	for(int i=d;i<=n;++i){
		f[i]=fg[i]=0,s[i]=1e9;
		if(nxt[i]==i)break;
	}
	s[d]=0,f[d]=1;
	q.push(d);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(fg[p])continue;
		fg[p]=1;
		for(int i=p+1;i<=nxt[p];++i){
			if(fg[i]||f[i]>2)continue;
			if(s[i]>s[p]+1){
				s[i]=s[p]+1,f[i]=f[p];
				q.push(i); 
			}
			else if(s[i]==s[p]+1)f[i]+=f[p]; 
		}
	}
	for(int i=d;i<=n;++i){
		ans+=(f[i]==2);
		if(nxt[i]==i)break;
	}
	return;
}
void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>z[i];
	pre[n+1]=n+1;
	for(int i=n;i;--i){
		pre[i]=pre[i+1];
		while(pre[i]>1&&z[i]-z[pre[i]-1]<=m)--pre[i];
	}
	for(int i=1;i<=n;++i){
		nxt[i]=nxt[i-1];
		while(nxt[i]<n&&z[nxt[i]+1]-z[i]<=m)++nxt[i];
	}
	for(int i=1;i<=n;++i){
		bfs(i);
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
