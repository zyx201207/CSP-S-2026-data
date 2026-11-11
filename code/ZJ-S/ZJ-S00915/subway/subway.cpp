#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int c,n,m,d,q,w[maxn],K[maxn],x,y,ans,t[505][505],X,Y;
bool flag[maxn];
vector<vector<int> >p(maxn+5);
vector<vector<int> >P(maxn+5);
int minn(int l1,int l2){
	if(l1<=l2){return l1;}
	else{return l2;}
}
//void dfs(int T,int now,int line){
//	if(now==y){ans=minn(ans,T);return ;}
//	cout<<T<<" "<<now<<"\n";
//	for(int i=0;i<(int)(p[line].size());i++){
//		if(flag[p[line][i]]!=1){
//			flag[p[line][i]]=1;
//			//cout<<p[now][i]<<":::::\n";
//			dfs(T,p[line][i],line);
//			for(int j=1;j<=m;j++){
//				if(t[j][p[now][i]]!=0){
//					for(int k=1;k<=m;k++){
//						if(j!=k&&t[k][p[line][i]]!=0){
//							cout<<j<<" "<<k<<"\n";
//							dfs(T+t[j][p[line][i]]+t[k][p[line][i]],now,p[now][i]);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//void solve(){
//	memset(flag,false,sizeof(flag));
//	flag[x]=1;ans=INT_MAX;
//	dfs(0,x,P[x][0]);
//	cout<<ans+w[x]+w[y]<<"\n";
//}
void solve(){
	cout<<w[x]+w[y]<<"\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		cin>>K[i];
		for(int j=1;j<=K[i];j++){
			cin>>X>>Y;
			p[i].push_back(X);
			P[X].push_back(i);
			t[i][X]=Y;
		}
	}
	while(q--){
		cin>>x>>y;
		solve();
	}
	return 0;
}
