#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,f,cnt1,cnt2,cnt3;
long long ans;
vector<int> w,g;
vector<vector<int> >k,d,c;
int z,x,y;
//bool bfs(int x,int y){
//	
//}
//bool bfs1(int x,int y){
//	for(int i=1;i<=2;i++){
//		if(c[x][i]==y){
//			ans+=k[c[x][i]][x];
//			return 1;
//		}
//		else{
//			if(bfs(c[x][i],y)==1){
//				ans+=[c[x][i]][c[x][i]];
//			}
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x!=2){
			f=1;
		}
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			k[y][i]=z;
			c[i][++cnt1]=y;
			d[y][++cnt2]=i;
			g[y]++;
		}
	}
	while(q--){
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		if(n==2){
			int minn=N;
			for(int i=1;i<=g[x];i++){
				minn=min(minn,k[x][i]);
			}
			ans+=1ll*minn;
			minn=N;
			for(int i=1;i<=g[y];i++){
				minn=min(minn,k[y][i]);
			}
			ans+=1ll*minn;
			cout<<ans;
		}
//		if(d==2||f==0){
//			
//		}
	}
	return 0;
}
