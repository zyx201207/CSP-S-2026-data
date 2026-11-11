#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10; 
int n,m,f[N][35];
ll arr[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		for(int j=30;j>=0;j--){
			if(arr[i]&(1<<j)){
				f[i][j]=1;
			}
		}
	}
	int sum=0;
	bool fl=0;
	for(int i=30;i>=0;i--){
		int y=0,p=sum;
		sum=0;
		//cout<<(1<<i)<<" ";
		for(int j=1;j<=n;j++){
			if(f[j][i]==1 && (vis[j]==1 || fl==0)){
				vis[j]=1;
				y++;
				//cout<<arr[j]<<' ';
				if(sum==0){
					sum=arr[j];
				}
				else sum&=arr[j];	
			}
			else vis[j]=0;
		}
		if(y==m){
			break;
		}
		else{
			if(y>m){
				fl=1;
			}
			else{
				if(fl!=1){
					fl=0;
					memset(vis,0,sizeof(vis));
				}
			}
		}
		//cout<<sum<<"\n";
	}
	cout<<sum;
	return 0;
}
