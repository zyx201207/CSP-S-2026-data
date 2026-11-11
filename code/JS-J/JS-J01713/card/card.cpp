#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],sum[100005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) sum[j]=a[j];
			for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=j-1;k>=i;k--){
				if(sum[j]==sum[k]){
					flag=k;
					break;
				}
			}
				if(flag>0){
				for(int k=j;k>flag;k--) sum[k]=0;
				}
			}
			for(int j=i;j<=n;j++){
				ans[sum[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
