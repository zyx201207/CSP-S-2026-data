#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	} 
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			long long cnt=a[j]*(j-i+1)-s[j]+s[i-1]; 
			if(cnt<=m){
				 ans=max(ans,(j-i+1) );
			}
		}
	}	
	cout<<ans;
	return 0;
}
	
