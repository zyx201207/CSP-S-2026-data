#include<bits/stdc++.h>
#define endline cout<<"\n"
#define int long long
using namespace std;
//I ? ccf
const int N=505,M=5e5+5,X=25;
struct node{
	vector<int> h,t;
	int w,k;
}a[N];
int c,n,m,d,q,in,nd=-2e16;
void solve(int x,int y);
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].w;
	}for(int i=1;i<=n;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++){
			cin>>in;
			a[i].h.push_back(in);
			nd=max(in,nd);
			cin>>in;
			a[i].t.push_back(in);
		}
	}long long g[nd+1][nd+1]={};
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].k;j++){
			for(int o=0;o<j;o++){
//				cout<<a[i].t[j]+a[i].t[o]<<"\n";
				g[a[i].h[o]][a[i].h[j]]=a[i].t[j]+a[i].t[o];
				g[a[i].h[j]][a[i].h[o]]=a[i].t[j]+a[i].t[o]; 
			}
		}
	} 
//	for(int i=1;i<=nd;i++){
//		for(int j=1;j<=nd;j++) cout<<g[i][j]<<" ";
//		endline;
//	}
	for(int i=1;i<=nd;i++) for(int j=1;j<=nd;j++){
		if(g[i][j]==0) g[i][j]=2e16;
		if(i==j) g[i][j]=0;
	} 
	for(int rp=1;rp<=nd;rp++){
		for(int i=1;i<=nd;i++){
			for(int j=1;j<=nd;j++){
				if(i==j) continue; 
				if(rp!=i&&rp!=j&&g[i][rp]+g[rp][j]<=g[i][j]&&g[i][rp]<=1e16&&g[rp][j]<=1e16) g[i][j]=g[i][rp]+g[rp][j]; 
			}
		} 
	}
//	for(int i=1;i<=nd;i++){
//		for(int j=1;j<=nd;j++) cout<<g[i][j]<<" ";
//		endline;
//	}
	int x=0,y=0;
	while(q--){
		cin>>x>>y;
		cout<<a[x].w+a[y].w+g[x][y];
		if(q) endline;
	}return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/