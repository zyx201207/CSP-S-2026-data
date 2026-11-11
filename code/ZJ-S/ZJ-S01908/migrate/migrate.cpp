/*
首先盲猜Floyd算所有的最短路（虽然说显然是错误答案） 
我显然不会Floyd
太区了 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int f[1001][1001][2];
int flag[101][101][101];
int ans[1001][1001];
int a[10000001]; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
//		cout<<n<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<' '; 
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d){
					f[i][j][1]=f[j][i][1]=a[j]-a[i];
				}
				else{
					f[i][j][1]=f[j][i][1]=1e9;
				} 
				f[i][j][0]=1; 
			}
		}
		memset(ans,0,sizeof(ans));
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(f[i][j][1]>f[i][k][1]+f[k][j][1]){
						f[i][j][1]=f[i][k][1]+f[k][j][1];
						f[i][j][0]++;
					}
					if(i!=k and k!=j and j!=i and f[i][j][1]==f[i][k][1]+f[k][j][1] and f[i][j][0]>1 and flag[i][j][k]==0 and (f[i][k][1]<=d and f[k][j][1]<=d)){
						ans[i][j]++;
						flag[i][j][k]=flag[i][k][j]=flag[j][i][k]=flag[j][k][i]=flag[k][j][i]=flag[k][i][j]=1;
//						cout<<i<<' '<<j<<' '<<k<<endl;
					}
				}
			}
		}
//		cout<<endl;
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ans[i][j]==2){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	
	
	
	return 0;
}
