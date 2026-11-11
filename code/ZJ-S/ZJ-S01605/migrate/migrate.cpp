#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N];
int ans[N][N];
int n,d;
int cnt;
void dfs(int u,int sum){
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]>d){
			break;
		}
		ans[i][sum+1]++;
		dfs(i,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=502;k++){
					ans[j][k]=0;
				}
			}
			dfs(i,0);
			for(int j=1;j<=n;j++){
				for(int k=1;k<=502;k++){
					if(ans[j][k]!=0){
						if(ans[j][k]==2){
							cnt++;
//							cout<<i<<' '<<j<<'\n';
						}
						break;
					}
				}
				
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}