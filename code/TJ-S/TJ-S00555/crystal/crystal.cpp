#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans;
bool isA=1;
bool isB=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i+1){
			isA=0;
		}
	}
//	if(n>=2){
//		long long cha=a[1]-a[0];
//		for(long long i=0;i<n;i++){
//			if(a[i+1]-a[i]!=cha){
//				isB=0;
//			}
//		}
//		if(isB==1){
//			long long temp=1;
//			long long ganggang=0;
//			long long last;
//			for(;;){
//				ganggang+=temp;
//				temp+=cha;
//				if(ganggang>m){
//					break;
//				}else{
//					last=ganggang;
//				}
//			}
//			m=last;
//			for(long long i=0;i<=m;i++){
//				if((a[i]-a[i-1]+a[i]-a[0])*(i-1)==2*m){
//					cout<<i;
//					return 0;
//				}
//			}
//			return 0;
//		}
//		return 0;
//	}
	if(isA==1){
		long long temp=1;
		long long ganggang=0;
		long long last;
		for(;;){
			ganggang+=temp;
			temp++;
			if(ganggang>m){
				break;
			}else{
				last=ganggang;
			}
		}
		m=last;
		for(long long i=0;i<=m;i++){
			if(i*i-i==2*m){
				cout<<i;
				return 0;
			}
		}
		return 0;
	}
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		long long sum=0;
		long long ans3=0;
		int j=i;
		while(m>0 && j<n){
			if(sum=a[j]){
				ans3++;
				j++;
			}
			if(m+sum-a[j]>=0){
				m-=(a[j]-sum);
				sum=a[j];
			}else{
				break;
			}
		}
		ans=max(ans,ans3);
	}
	cout<<ans;
	return 0;
} 
// 5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
