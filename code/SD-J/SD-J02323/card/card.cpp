#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500100;
int n,m,a[N],dp[N],k[N],p[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[j]=a[j];
			for(int z=1;z<=j-1;z++){
				if(dp[j]==a[z]){
					for(int y=1;y<=j-1;y++){
						dp[y]=0;
					}
				}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<dp[i]<<" ";
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				if(dp[j]==l){
					p[l]++;
				}
			}
		}
		for(int i=1;i<=n;i++)
			dp[i]=0;	
	}
	for(int i=1;i<=m;i++)
		cout<<p[i]<<" ";
	return 0;
} 
