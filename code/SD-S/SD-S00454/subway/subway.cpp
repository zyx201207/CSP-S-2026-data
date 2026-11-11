#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200,M=1010,D=20,Q=1e5+10;
int c,n,m,d,pla,a,t,x,y;
int w[M],k[N],mn=INT_MAX; 
int e[M][N],lst[N];
int nxt(int lin,int pres){
	for(int i=pres+1;i<=m;i++){
		if(e[i][lin]!=-1)return i;
	}
}
void dfs(int idx,int tim,int lin){
	if(idx==y){
		mn=min(mn,tim+e[idx][lin]+w[idx]);
		return;
	}
	if(idx>y)return;
	if(tim>mn)return;
	for(int i=1;i<=n;i++){
		if(e[idx][i]!=-1&&lst[i]!=idx){
			if(i==lin)dfs(nxt(i,idx),tim,i);
			else dfs(nxt(i,idx),tim+e[idx][lin]+e[idx][i],i);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>pla;
	memset(e,-1,sizeof(e));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			e[a][i]=t;
			lst[i]=max(lst[i],a);
		}
	}
	while(pla--){
		cin>>x>>y;
		mn=INT_MAX;
		for(int i=1;i<=n;i++){
			if(e[x][i]!=-1&&x!=lst[i]){
				dfs(nxt(i,x),w[x]+e[x][i],i);
			}
		}
		cout<<mn<<"\n";
	}
	return 0;
}

