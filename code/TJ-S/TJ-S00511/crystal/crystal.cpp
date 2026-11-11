#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long m;
long long n;
long long a[500005]={};
long long cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	for(long long i=n;i>=1;i--){
		long long tmp=m;
		long long tmp2=0;
		for(long long j=i;j>=1;j--){
			if(tmp>=(a[i]-a[j])){
				tmp-=(a[i]-a[j]);
				tmp2++;
			}else{
				break;
			}
		}
		cnt=max(cnt,tmp2);
	}
	cout<<cnt;
	return 0;
}
