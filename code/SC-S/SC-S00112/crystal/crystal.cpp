#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++) c[i]=a[i+1]-a[i];
	if(n<=5000){
		for(int i=n;i>=1;i--){
			long long h=0,cs=1;
			for(int j=1;j<=i-1;j++){
				if(h+c[i-j]>m){
					maxn=max(maxn,cs);
					break;
				} 
				h+=c[i-j];
				cs++;
				//cout<<a[i]<<' '<<a[i-j]<<' '<<h<<' '<<cs<<endl;
			}
			//cout<<endl;
		}
	}else{
		long long sh;
		for(int i=2;i<=n;i++){
			sh=(a[1]+a[i])*i/2;
			if(sh>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	cout<<maxn;
	return 0;
} 