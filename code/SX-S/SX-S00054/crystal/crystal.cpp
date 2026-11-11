#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
long long a[M],n,m,num=0,ma,dp[M],dph[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)
		ma=a[i];
		ma=max(ma,a[i]);
		num+=a[i];
	}
	if(m>=n*ma-num){
		cout<<n<<endl;
	}else{
		sort(a+1,a+1+n);
		long long lsn=0,qz=0;
		int as=1,l=1;
		for(int i=2;i<=n;i++){
			qz=a[i]-a[i-1];
			lsn+=qz*(i-l);
			while(lsn>m){
				lsn-=a[i]-a[l];
				l++;
			}
			as=max(as,i-l+1);
		}
		cout<<as<<endl;
	}
}
