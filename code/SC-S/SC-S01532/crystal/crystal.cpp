#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum,ka=1,kb=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)ka=0;
		if(i>2&&(a[i]-a[i-1])!=(a[i-1]-a[i-2])){
			kb=0;
		}
	}
	sort(a+1,a+n+1);
	if(ka){
		long long sum=0,i;
		for(i=1;i<=n;i++){
			sum+=a[i];
			if(sum>m)break;
		}
		cout<<i;
		return 0;
	}
	else if(kb){
		long long as=a[2]-a[1],xx=0;
		long long sum=0,i;
		for(i=1;i<=n;i++){
			sum+=i;
			xx=sum*as;
			if(xx>m)break;
		}
		cout<<i;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		sum=0;
		for(long long j=i;j<=n;j++){
			if(j>=2&&sum!=0)sum+=((a[j]-a[j-1])*2);
			else if(j>=2&&sum==0)sum+=(a[j]-a[j-1]);
			if(sum>m){
				ans=max(j-i,ans);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}