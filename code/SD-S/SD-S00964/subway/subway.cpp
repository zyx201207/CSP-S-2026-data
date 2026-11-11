#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int c,n,m,d,q,k[N],t[N][500],w[N],a[N][500],xi[500][N],cnt[500];
int dis[500];
struct node{
	int z,x;
};
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			xi[a[i][j]][++cnt[a[i][j]]]=i;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=ans+w[x]+w[y],cnt=1e9;
		for(int i=1;i<=n;i++){
			bool fl1=0,fl2=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					fl1=1;
				}else if(a[i][j]==y){
					fl2=1;
				}
			}
			if(fl1&&fl2){
				cnt=min(cnt,t[i][x]+t[i][y]);
			}
		}
		cout<<ans+cnt;
	}
	return 0;
}
