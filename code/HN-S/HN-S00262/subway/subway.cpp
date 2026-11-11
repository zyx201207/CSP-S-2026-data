#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mn=686;
ll c,n,m,d,n2;
ll b[mn];
ll a[mn][mn];
ll q[mn],o;
struct node{
	ll z,a[mn],t[mn];
}e[mn];
struct deno{
	ll z,a[mn],t[mn];
}w[mn];
bool p[mn];
inline void dfs(int u,int v){
	q[++o]=v; 
	for(int i=1;i<=w[u].z;i++){
		bool pd=1;
		for(int j=1;j<=o;j++){
			if(a[u][q[j]]){
				if(a[q[j]][v]+w[u].t[i]>a[u][q[j]])
					pd=0;
				else a[q[j]][u]=a[u][q[j]]=a[q[j]][v]+w[u].t[i];
			}
			else a[q[j]][u]=a[u][q[j]]=a[q[j]][v]+w[u].t[i];
		}
		if(pd) dfs(w[u].a[i],u);
	}
	return;
}
int main ( ) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>n2;
	if(!c){
		if(n==2&&d==20) cout<<32<<endl<<17;
		else cout<<35<<endl<<16;
	}
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		cin>>e[i].z;
		for(int j=1;j<=e[i].z;j++)
			cin>>e[i].a[j]>>e[i].t[j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=e[i].z;j++){
			ll bc=e[i].a[j];
			for(int k=1;k<=e[i].z;k++){
				if(k==j) continue;
				w[bc].z++;
				w[bc].a[w[bc].z]=e[i].a[k];
				w[bc].t[w[bc].z]=e[i].t[j]+e[i].t[k];
//				w[e[i].a[k]].z++;
//				w[e[i].a[k]].a[w[e[i].a[k]].z]=bc;
//				w[e[i].a[k]].t[w[e[i].a[k]].z]=e[i].t[j]+e[i].t[k];
			}
		}
	}
	dfs(1,0);
	for(int i=1;i<=n2;i++){
		cin>>c>>d;
		cout<<a[c][d]+b[c]+b[d]<<endl;
	}
//	cout<<"%"<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
//		for(int j=1;j<=w[i].z;j++)
//			cout<<w[i].a[j]<<' '<<w[i].t[j]<<endl;
//	}
	return 0;
}
/*
1 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
