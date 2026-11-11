#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k,flag=1,flag2=1,x,y,ans,num;
vector<int>a[500005];
vector<int>t[500005];
vector<pair<int,int> >edge1[500005];
vector<pair<int,int> >edge[500005];
map<pair<int,int>,int>mo;
map<pair<int,int>,int>jl;
void dfs(int now,int fa){
	if(now==y){
		ans=min(ans,num);
		return ;
	}
	for(int i=0;i<edge1[now].size();i++){
		int nxt=edge1[now][i].first,jl=edge1[now][i].second;
		if(nxt==fa){
			continue;
		}
		num+=jl;
		dfs(nxt,now);
		num-=jl;
	}
} 
void dfs2(int now,int fa,int kd){
	if(now==y){
		num=num+jl[{kd,now}];
		ans=min(ans,num);
		return ;
	}
	for(int i=0;i<edge[now].size();i++){
		int nxt=edge[now][i].first,z=edge[now][i].second;
		if(nxt==fa){
			continue;
		}
		if(z==kd){
			dfs2(nxt,now,kd);
		} 
		else{
			num+=(jl[{kd,now}]+jl[{z,now}]);
			dfs2(nxt,now,z);
			num-=(jl[{kd,now}]+jl[{z,now}]);
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2){
			flag=0;
		} 
		for(int j=0;j<k;j++){
			int ls1,ls2;
			cin>>ls1>>ls2;
			mo[{i,ls1}]=1;
			jl[{i,ls1}]=ls2;
			a[i].push_back(ls1);
			t[i].push_back(ls2);
			if(j!=0){
				edge1[a[i][j-1]].push_back({a[i][j],t[i][j-1]+t[i][j]});
				edge1[a[i][j]].push_back({a[i][j-1],t[i][j-1]+t[i][j]});
				edge[a[i][j-1]].push_back({a[i][j],i});
				edge[a[i][j]].push_back({a[i][j-1],i});
			}
		} 	
	}
	if(flag==1){
		while(q--){
			cin>>x>>y;
			ans=0x3f3f3f3f;
			num=0;
			dfs(x,0);
			cout<<ans+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			if(mo[{i,x}]==1){
				num=0;
				num+=jl[{i,x}];
				dfs2(x,0,i);
				num-=jl[{i,x}];
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	} 
	return 0;
}

