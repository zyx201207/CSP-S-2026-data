#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long sum[N],ans=0;
int main(){
  	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	long long i=1,j=1;
	while(j<=n){
		long long cnt=a[j]*(j-i+1)-(sum[j]-sum[i-1]);
		if(cnt>m)i++;
		else if(cnt<=m){
			if(cnt==m)i++;
			ans=max(ans,j-i+1),j++;
		}
	}
	cout<<ans;
	return 0;
}

