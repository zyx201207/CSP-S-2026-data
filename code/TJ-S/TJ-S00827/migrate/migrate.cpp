#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int arr[N]; 
int brr[N];
int g[1000][1000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while(t--){
		int n,m;
		cin >>n>>m;
		for(int i=1;i<=n;i++){
			arr[i]=0;
			cin>>arr[i];
		}
		sort(arr+1,arr+1+n);
		for(int i=2;i<=n;i++){
			brr[i]=arr[i]-arr[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			int cnt=1,sum=0;
			for(int j=i+1;j<=n;j++){
				if(brr[j]<=m){
					sum+=brr[j];
					if(sum>m){
						sum=brr[j];
						cnt++;
					}
					g[i][j]=cnt;
					g[j][i]=cnt;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=i;k<=j;k++){
					if(g[i][k]+g[k][j]==g[i][j]){
						cnt++;
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
