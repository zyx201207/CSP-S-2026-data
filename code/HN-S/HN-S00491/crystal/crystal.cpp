#include<bits/stdc++.h>
using namespace std;

int n,m,a[50005],cnt[50005],minn,sum[50050],k,ans,x[50050];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i];
		cnt[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[j]+=cnt[i+1];
		}
		k=0;
		for(int j=1;j<=i;j++){
			if(k>m){
				break;
			}
			k+=abs((a[j]-x[j]));
			if(k>m){
				break;
			}
		}
		if(k>m){
			break;
		}
		for(int j=1;j<=n;j++){
			if(a[j]==a[j+1]){
				sum[a[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>ans){
			ans=sum[i];
		}
	}
	cout<<ans;
	return 0;
} 
