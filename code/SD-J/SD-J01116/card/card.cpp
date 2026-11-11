#include<bits/stdc++.h>
using namespace std;
int M[300005];
int dp[200005];
int N[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>N[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) dp[i]=0;
		for(int j=i;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(N[j]==N[k]){
					for(int o=j;o<k;o++){
						dp[o]=1;
					}
					j=k;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(dp[j]!=1){
				M[N[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<M[i]<<' ';
	}
	return 0;
}
