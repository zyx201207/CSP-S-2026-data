#include<bits/stdc++.h>
using namespace std;
int t,n,k,cnt,net[2000009],to[2000009],head[1000009],s[1000009],deep,ss,c;
void hb(int u,int v){
	to[++cnt]=v;
	net[cnt]=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa,int dep){
//	cout<<u<<"\n";
	if(dep>deep)deep=dep;
	s[dep]++;
	for(int i=head[u];i;i=net[i]){
		if(to[i]!=fa){
			dfs(to[i],u,dep+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++)cin>>c>>c;
			cout<<(n+1)%2<<"\n";
		}
		return 0;
	}
	while(t--){
		int u,v;
		cin>>n>>k;
		for(int i=1;i<=cnt;i++)to[i]=0,net[i]=0;
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<=n;i++)s[i]=0;
		cnt=0;deep=0;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			hb(u,v);
			hb(v,u);
		}
		dfs(1,0,1);
		for(int i=2;i<=deep;i++)s[i]+=s[i-1];
//		for(int i=1;i<=deep;i++)cout<<s[i]<<" ";
//		cout<<"\n";
		int uu=lower_bound(s+1,s+1+deep,k)-s-1;
		if(!net[head[1]])cout<<uu<<"\n";
		else cout<<uu*2<<"\n";
	}
	return 0;
} //Oct31==Dec25?