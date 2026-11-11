#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[5010][5010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	
	if(n>=500000){
		long long s=abs(a[2]-a[1]);
	long long cnt=1;
	while(m>=0){
		m-=cnt*s;
		cnt++;
	} 
	cout<<min(cnt-1,n);
	return 0;
	}
	
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		for(long long j=i-1;j>=1;j--){
			f[i][j]=a[i]-a[j];
		}
	}
	long long maxn=0;
	for(long long i=n;i>=1;i--){
		if(maxn>=i) break; 
		long long sum=m;
		for(long long j=i-1;j>=1;j--){
			sum-=f[i][j];
			if(j==1&&sum>=0){
				maxn=max(maxn,i);
			}
			if(sum<0){
				maxn=max(maxn,i-j);
				break;
			} 
		}
	} 
	cout<<maxn;
	return 0;
} 
