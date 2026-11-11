#include<bits/stdc++.h>
using namespace std;
long long a[500005],n;
long long m,c[500005];
bool h(int l,int r){
	long long k=0;
	long long sum=0;
	for(int i=l;2*i<=l+r;i++){
		k++;
		sum+=k*(c[i]+c[l+r-i]);
		if(2*i==l+r)sum-=k*c[i];
		if(sum>m)return 0;
	}
	//cout<<l<<" "<<r<<" "<<k<<" "<<sum<<"\n";
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	//for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	if(n>5000){
		long long d=c[2],i,ans=-1e9,cnt=1,sum=0;
		for(i=1;i<=n;i++){
			sum+=cnt*d;
			if(sum>m){
				printf("%lld\n",i);
				return 0;
			}
			if(i%2==0)cnt++;
		}
		printf("%d\n",n);
		return 0;
	}
	long long ans=-1e9,l=1;
	for(int i=2;i<=n;i++){
		while(!h(l+1,i)&&l<i)l++;
		ans=max(ans,(long long)(i-l+1));
		//cout<<l+1<<" "<<i<<"\n";
	}
	printf("%lld",ans);
	return 0;
}