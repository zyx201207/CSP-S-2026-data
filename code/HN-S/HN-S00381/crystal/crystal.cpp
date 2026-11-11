#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],max1=1,p1=1,p2=2,max2;
long long cnt,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max2=max(max2,a[i]);
		if(a[i]!=i)p1=0;
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2]))p2=0;
	}
	if(p1 && p2 && m>5000){
		for(int i=1;i<=max2;i++){
			sum+=i;
			if(sum>=m){
				cout<<i;
				return 0;
			}
		}
	}
	else if(m>5000 && p2){
		long long t=a[2]-a[1];
		for(int i=1;i<=max2;i+=t){
			sum+=i;
			if(sum>=m){
				cout<<i;
				return 0;
			}
		}
	}
	long long f=m;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		for(int j=i-1;j>=1;--j){
			if(f>=(a[i]-a[j])){
				cnt++;
				f-=(a[i]-a[j]);
			}
		}
		f=m;
		max1=max(cnt,max1);
		cnt=0;
	}
	cout<<max1+1;
	return 0;
} 
