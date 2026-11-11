#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],b[500005],ed=0,ans[300005],dp[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int f=1;f<=n;i++){
			b[i]=0;
		}
		for(int f=1;f<=m;f++){
			dp[i]=-1;
		}
		for(int j=i;j<=n;j++){
			if(dp[a[j]]!=-1){
				for(int l=dp[a[j]];l<=ed;l++){
					for(int f=1;f<=m;f++){
						if(f==b[l]){
							dp[f]=-1;
						}
					}
					b[l]=0;
				}
				ed=dp[a[j]]-1;
			}
			else{
				dp[a[j]]=j;
				ed++;
				b[ed]=a[j];
			} 
		}
		for(int f=1;f<=m;f++){
			if(dp[f]!=-1){
				ans[f]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
