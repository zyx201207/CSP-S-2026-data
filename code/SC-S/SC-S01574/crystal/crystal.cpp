#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long b[500050];
long long c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin >> n >> m;
	c[1]=0;
	for(long long i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	long long f=1;
	long long cnt=a[2]-a[1];
	for(long long i = 2 ; i <= n ; i++){
		if(a[i]-a[i-1]!=cnt){
			f=0;
			break;
		}
	}
	if(f){
		long long sum=1,cnt1=cnt;
		while(true){
			if(m<cnt1){
				cout << sum;
				break;
			}
			m-=cnt1;
			++sum;
			cnt1+=cnt;
		}
	}
	else{
		long long maxn=-1;
		sort(a+1,a+n+1);
		for(long long i = 2 ; i <= n ; i++){
			b[i-1]=a[i]-a[i-1];
		}
		for(long long i = 1 ; i < n ; i++){
			c[i+1]=b[i]*i+c[i];
		}		
		for(long long i = 1 ; i <= n ; i++){
			for(long long j = i+1 ; j <= n ; j++){
				long long x=c[j]-c[i]-(i-1)*(a[j]-a[i]);
				if(x<=m){
					maxn=max(maxn,j-i+1);
				}
			}
		}	
		cout << maxn;
	}	
	
	return 0;
}