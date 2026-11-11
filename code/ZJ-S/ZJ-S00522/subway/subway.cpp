#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505+5,M=5e5+5;
ll c,n,m,d,q,w[M],k[N],a[N][N],t[N][N],mx[M];
queue<pair<ll,ll> >qu;
void bfs(ll f,ll e){
	while(!qu.empty())qu.pop();
	qu.push(make_pair(f,w[f]));
	while(!qu.empty()){
		int u=qu.front().first,v=qu.front().second;
		qu.pop();
		for(int i=1;i<=n;i++){
			int ok=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==u){
					ok=j;
					break;
				}
			}
			if(ok){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==u)continue;
					ll s=v+t[i][j]+t[i][ok];
					if(mx[a[i][j]]>s){
						qu.push(make_pair(a[i][j],s));
						mx[a[i][j]]=s;	
					}
				}
			}
		}
	}
	printf("%lld\n",mx[e]+w[e]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++)mx[i]=4e18;
		bfs(x,y);
	}
	return 0;
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
