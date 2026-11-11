#include<bits/stdc++.h>
using namespace std;
int a[200050],cnt[200050],sum[200050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}if(m==2){
		sum[a[n]]=n;
		for(int i=n-1;i>=1;i--){
			if(a[i]!=a[n]){
				sum[a[i]]=i;
				cout<<sum[1]<<" "<<sum[2];
				return 0;
			}
		}
		return 0;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(cnt[j]==a[i]){
				for(int z=j;z<i;z++)cnt[z]=-1;
				cnt[i]=a[i];
			}
		}for(int j=1;j<=m;j++){
			if(cnt[j]>=1)sum[cnt[j]]++;
			cnt[j]=0;
		}
	}for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
