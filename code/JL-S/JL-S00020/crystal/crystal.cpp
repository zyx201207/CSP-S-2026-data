#include<bits/stdc++.h>
using namespace std;
long long a[500000],maxs=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(long long i_1=0;i_1<n;i_1++)cin>>a[i_1];
	for(long long i_1=0;i_1<n;i_1++){
		for(long long i_2=1;i_2<n-i_1;i_2++){
			if(a[i_2]<a[i_2-1]){
				long long exc=a[i_2];
				a[i_2]=a[i_2-1];
				a[i_2-1]=exc;
			}
		}
	}
	for(long long i_1=0;i_1<n-1;i_1++){
		long long sum=0;
		if(n-i_1<=maxs)break;
		if(i_1!=0)if(a[n-i_1-1]==a[n-i_1])break;
		for(long long i_2=i_1+1;i_2<n;i_2++){
			sum+=a[n-i_1-1]-a[n-i_2-1];
			if(sum>m){
				if(i_2-i_1>maxs)maxs=i_2-i_1;
				break;
			}
			if(i_2==n-1){
				if(i_2-i_1+1>maxs)maxs=i_2-i_1+1;
				break;
			}
		}
	}
	cout<<maxs;
	return 0;
}
