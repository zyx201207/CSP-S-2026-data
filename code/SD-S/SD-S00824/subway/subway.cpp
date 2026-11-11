#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
//#define int long long
using namespace std;
const int MAXN=5e5+20;
struct Node{
	int v,nxt;
}e[MAXN];
struct node{
	int sta,tim;
};
int h[MAXN],tot;
int c,n,m,d,q;
int fa[MAXN];
int ww[MAXN],k[MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=m;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
		}
	}

	for(int i=1;i<=q;i++){
		int s,t;cin>>s>>t;
		cout<<ww[s]+ww[t]<<'\n';
	}
	return 0;
} 
/*

*/
