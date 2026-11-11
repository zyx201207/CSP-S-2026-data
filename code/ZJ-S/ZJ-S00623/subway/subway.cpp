#include<bits/stdc++.h>
using namespace std;
#define ll long long
//OMG怎么是傻逼图论 
//读完题目
//卧槽我的肚子好疼
 
const int C=30,L=505;
const int N=300;
const int M=5e5+10,D=25,Q=1e5+10;
struct node{
	int  a;
	int t;
};
struct edge{
	int x;
	int y;
};
int c,n,m,d,q;
int w[M];
int k[N];
int t[N][M];
node yf[N][M];
edge ed[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>yf[i][j].a>>yf[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ed[i].x>>ed[i].y;
	}
	//我的头好难受…… 
	return 0;
}
