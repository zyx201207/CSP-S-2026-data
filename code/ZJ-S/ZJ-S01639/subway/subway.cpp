#include<bits/stdc++.h>
using namespace std;
const int N=505,M=2e4+5;
int c,n,m,d,q,w[N],k[N],a[N][M],f[N][505],l[N][N],b[N],t[N][M];
//int ;
int dfs(int x,int y,int t){
	if(l[x][y]!=0){
		return t+l[x][y];
	}
	int ans=INT_MAX-1;
	for(int i=1;i<=m;i++){
		if(l[x][i]!=0&&b[i]!=1){
			b[i]=1;
			ans=min(dfs(i,y,t+l[x][i]),ans);
			b[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	cout<<"w ok"<<'\n';
//	for(int i=1;i<=m;i++){
//		cout<<w[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			f[a[i][j]][i]=1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<f[s][i]
//		}
//	}
//	cout<<"k ok"<<'\n';
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int s=1;s<=n;s++){
				if(f[i][s]==1&&f[j][s]==1){
//					cout<<i<<" "<<j<<" "<<endl;
					if(l[i][j]==0){
						l[i][j]=t[s][i]+t[s][j];
					}else{
						l[i][j]=min(l[i][j],t[s][i]+t[s][j]);
					}
					l[j][i]=l[i][j];
				}
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<l[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	while(q--){
		int start,end,ans=0;
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
		cin>>start>>end;
//		cout<<"st++:";
//		cout<<start<<" "<<end<<' ';
		ans+=w[start];
		ans+=w[end];
//		cout<<ans<<"\n";
		if(l[start][end]!=0){
			ans+=l[start][end];
			cout<<ans<<'\n';
			continue;
		}
		ans=dfs(start,end,ans);
		cout<<ans<<'\n';
//		cout<<"ok++"<<'\n';
	}
	return 0;
}