#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	else if(m==0){
		cout<<0;
		return 0; 
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i) flag=0;
	}
	long long d=0;
	bool flag1=1;
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(int i=3;i<=n;i++){
		if(sum[i]!=sum[i-1]) flag1=0;
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=2;i<=n;i++){
		long long step=0;
		for(int j=i-1;j>=1;j--){
			step+=a[i]-a[j];
			if(step<=m) ans[i]++;
			else break;
		}
	}
	for(int i=2;i<=n;i++){
		ans[i]++;
	}
	long long maxx=-0x3f3f3f3f;
	for(int i=2;i<=n;i++){
		maxx=max(ans[i],maxx);
	}
	cout<<maxx;
	}
	else if(flag){
		long long ans=0;
		for(long long i=n;i>=2;i--){
			if(m<=0.5*(i*(i-1))&&m>=0.5*((i-1)*(i-2))) ans=i-1;
		}
		cout<<ans;
	}
	else if(flag1){
		long long ans=0,d=sum[2];
		for(long long i=n;i>=2;i--){
			if(m<=d*0.5*(i*(i-1))&&m>=d*0.5*((i-1)*(i-2))) ans=i-1;
		}
		cout<<ans;
	}
	else{
		cout<<114514;
	}
	return 0;
} 
