#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=0,minn=LLONG_MAX;
long long a[500050];
long long sum[500050];
void work1(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long sum=0,tot=0;
		for(long long j=i;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum>m) break;
			else tot++;
		}
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
}
long long pre[2000010];
void work2(){
	long long sum=m/maxx;
	long long tot=sqrt(m*2)+1;
	long long ans=0;
	for(long long i=1;i<=tot;i++){
		pre[i]=pre[i-1]+i;
		if(pre[i]>sum){
			ans=i-1;
			break;
		}
	}
	cout<<min(n,ans)<<endl;
}
void work3(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long sum=0,tot=0;
		for(long long j=i;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum>m) break;
			else tot++;
		}
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		sum[i]=a[i+1]-a[i];
		maxx=max(maxx,sum[i]);
		minn=min(minn,sum[i]);
	}
	if(n<=5000){
		work1();
		return 0;
	}
	else if(maxx==minn){
		work2();
		return 0;
	}
	else{
		work3();
		return 0;
	}
	return 0;
}
