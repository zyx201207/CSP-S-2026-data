#include<bits/stdc++.h>
using namespace std;
#define _ long long
#define cx hdahuhudshfa
#define cy jihjhfsuguai
_ a,b,c,d,e,f,sons[1000002],ans,ansen,cx,cy;//c=choose
vector<_>v[1000001];
void dfs_sons(_ x,_ fa){
	sons[x]=1;
	for(_ i:v[x]){
		if(i!=fa){
			dfs_sons(i,x);
			sons[x]+=sons[i];
		}
	}
}
_ dfs_ans(_ x,_ fa,_ dep){
	if(x==cx||x==cy)return 0;
	_ mx=dep,mx2=dep,n;
	for(_ i:v[x]){
		if(i!=fa){
			n=dfs_ans(i,x,dep+1);
			if(n>mx){
				mx2=mx;
				mx=n;
			}
			else if(n>mx2)mx2=n;
		}
	}
	ans=max(ans,(mx-dep)+(mx2-dep)+1);
	return mx;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(_ Q=1;Q<=b;Q++){
		cin>>c>>d;
		for(_ i=1;i<c;i++)cin>>e>>f,v[e].push_back(f),v[f].push_back(e);
		ansen=LLONG_MAX;
		for(_ i=1;i<=c;i++){
			dfs_sons(i,0);
			for(cx=1;cx<=c;cx++)for(cy=cx;cy<=c+1;cy++){
				if(sons[cx]+sons[cy]>d)continue;
				ans=0;
				dfs_ans(i,0,0);
				ansen=min(ansen,ans);
			}
		}
		cout<<ansen<<'\n';
		for(_ i=1;i<=c;i++)v[i].clear();
	}
	return 0;
}