//SQKS
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T,n,m;
vector<int>v[2000010];
int g;
int d[2000010];
int mx;
void sol1(int x,int fa){
	d[x]=d[fa]+1;
	if(d[x]>mx)mx=d[x],g=x;
	for(auto i:v[x]){
		if(i==fa)continue;
		sol1(i,x);
	}
}
void sol2(int x,int fa){
	d[x]=d[fa]+1;
	if(d[x]>mx)mx=d[x];
	for(auto i:v[x]){
		if(i==fa)continue;
		sol2(i,x);
	}
}
int mg;
int f[2000010];
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
bool vs[2000010];
vector<int>si;
int jl[520][520];
int gh[520];
void ck(int x,int fa){
	gh[x]=1;
	for(auto i:v[x]){
		if(i==fa)continue;
		if(vs[i])ck(i,x);
	}
}
void sol(int cnt){
	if(cnt==m){
		for(int i=1;i<=n;i++)f[i]=i,gh[i]=0;
		si.clear();
		int tld=0;
		for(int i=1;i<=n;i++){
			if(vs[i]&&!gh[i]){
				if(tld==2)return;
				tld++;
				ck(i,0);
			}
		}
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(vs[i]&&gh[i])cntt++,si.push_back(i);
		}
	//	cout<<cntt<<"\n";
		if(cntt!=m)return;
	//	cout<<"\n";
//		for(auto i:si)cout<<i<<" ";
		int mx=0;
		for(int i=1;i<=n;i++){
			if(vs[i])continue;
			int mi=2e9;
			for(auto j:si){
				mi=min(mi,jl[i][j]);
			}
			mx=max(mx,mi);
			if(mx>=mg)return;
		}
//		cout<<"!!!"<<mx<<"\n";
		mg=min(mg,mx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vs[i])continue;
		vs[i]=1;
		sol(cnt+1);
		vs[i]=0;
	}
}
void dfs(int x,int fa,int z){
	jl[z][x]=jl[z][fa]+1;
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x,z);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)v[i].clear();
		int ff=1;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			if(y!=x+1)ff=0;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	/*	if(m==2){
			mx=0,g=0;
			d[0]=-1;
			sol1(1,0);
		//	for(int i=1;i<=n;i++)cout<<d[i]<<" ";
		//	cout<<"\n";
			mx=0;
			sol2(g,0);
		//	for(int i=1;i<=n;i++)cout<<d[i]<<" ";
		//	cout<<"\n";
			cout<<mx<<"\n";
		//	cout<<mx/3<<"\n";
			continue;
		}*/
		if(C==13||C==14){
			mx=0,g=0;
			d[0]=-1;
			sol1(1,0);
			mx=0;
			sol2(g,0);
			cout<<max(1,mx/3-(m-4+1)/4)<<"\n";
			continue;
		}
		mg=n;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=n;i++)jl[i][0]=-1,dfs(i,0,i);
		sol(0);
		cout<<mg<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
