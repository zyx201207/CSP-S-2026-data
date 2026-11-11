#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
int c,n,m,d,q;
ll dis[N][N];
ll w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			dis[i][j]=100000;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		vector<int> a(k+1);
		vector<int> t(k+1);
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			dis[a[j]+(i-1)*m][a[j]+m*n+m]=t[j];
			dis[a[j]+m*n+m][a[j]+(i-1)*m]=t[j];
			for(int l=1;l<=k;l++){
				dis[a[j]+(i-1)*m][a[l]+(i-1)*m]=0;
			}
		}
	}
	for(int i=1;i<=m*n+m;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m*n+m*2;i++){
		for(int j=1;j<=m*n+m*2;j++){
			for(int k=1;k<=m*2+m*n;k++){
				dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
			}
		} 
	}
	for(int i=1;i<=m*2+n*m;i++){
		for(int j=1;j<m+n*m;j++){
			cout<<i<<' '<<j<<' '<<dis[i][j]<<endl;
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		for(int j=a;j+m<=m*n+m;j+=m){
			for(int l=b;l+m<=m*n+m;l+=m){
//				cout<<j<<' '<<l<<'\n';
				if(dis[j][l]&&dis[j][l]!=100000){
					cout<<dis[j][l]+w[a]+w[b]<<endl;
				} 
			}
		}
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
