#include<bits/stdc++.h>
using namespace std;
void s(){
	int n,m;
	cin>>n>>m;
	int dp[m+10],a[m+10],b[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>dp[i];
	}
	for(int z=1;z<=n;z++){
		for(int i=z;i<=n;i++){
			for(int j=z;j<=n;j++){
				a[j]=dp[j];
				if(i<j){
					if(dp[z]==dp[j]){
						for(int k=i;k<j;k++){
							a[k]=0;
						}
					}
				}	
			
			}
			if(a[i]!=0){
				b[a[i]]+=1;
				cout<<a[i];
			}
	
		}
	
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	s();
	return 0;
} 
