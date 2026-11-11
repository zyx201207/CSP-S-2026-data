#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main () {
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	long long n,sum=0;
	long long m;
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		if(x!=abs(a[i]-a[i-1])){
			flag=1;
		}
	}
	if(flag==0){
		long long id=0;
	long long x=abs(a[2]-a[1]);
	for(int i=1;i<=n;i++){
		sum+=i;
		if(sum*x>m){
			id=i;
			break;
		}
	}
	cout<<id;
	}else{
		sort(a+1,a+n+1);
		long long sum1=0;
		long long maxx=-1;
		for(long long i=2;i<=n;i++){
			long long cnt=0,ans=-1,sum1=0;
			for(long long j=i-1;j>=1;j--){
				sum1+=abs(a[i]-a[j]);
				cnt++;
				if(sum1>m){
					 ans=cnt;
					 break;
				}
			}
			if(ans==-1){
				maxx=max(maxx,i);
			}else{
				maxx=max(maxx,ans);
			}
		}
		cout<<maxx;
	}
	
	return 0 ;
}

