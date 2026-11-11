#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool checkA=1,checkB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)checkA=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			if(i<=2)continue;
			checkB=0;
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(checkA==1){
		for(int i=n;i>=1;i--){
			long long t=1ll*i*(i-1)/2;
			if(t<=m){
				ans=i;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(checkB==1){
		int K=a[2]-a[1];
		m/=K;
		for(int i=n;i>=1;i--){
			long long t=1ll*i*(i-1)/2;
			if(t<=m){
				ans=i;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(i<=ans)break;
		long long sum=0,num=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum<=m)num++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}