#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long a[50010];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=-1;
	for(long long i=1;i<=n;i++){
		long long k=i,s=0,sum=0;
		while(k!=1){
			for(long long j=1;j<k;j++){
				if(a[k]-a[j]<=m&&a[k]-a[j]<=m-sum){
					s++;
					sum+=a[k]-a[j];
				}
			}
			ans=max(ans,s);
			k--;
		}
	}
	cout<<ans+1;
	return 0;
}
