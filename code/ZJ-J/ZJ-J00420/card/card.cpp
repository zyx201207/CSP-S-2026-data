#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[510000],f=1,sum[510000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f){
		int ans=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<i-1<<" ";
			}
		}
		return 0;
	}
	if(m<=2){
		int sum1=0,sum2=0;
		if(a[n]==1){
			sum1=n;
			sum2=n/2;
		}
		else{
			sum2=n;
			sum1=n/2;
		}
		cout<<sum1<<" "<<sum2;
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int cnt=0,vis[310000]={0},res[5100]={0};
			for(int j=i;j<=n;j++){
				if(vis[a[j]]==1){
					while(a[j]!=res[cnt]){
						vis[res[cnt]]--;
						cnt--;
					}
				}
				else{
					vis[a[j]]=1;
					res[++cnt]=a[j];
				}
			}
			for(int j=1;j<=cnt;j++){
				sum[res[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
	
	return 0;
}