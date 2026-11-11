#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],s,ans;
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	f=0;
	for(long long i=2;i<n;i++)
	    if(a[i]-a[i-1]!=a[i+1]-a[i]){
	    	f=1;
	    	break;
		}
	if(f==0){
		long long x=a[2]-a[1];
		for(long long i=1;i<n;i++){
			s+=x*i;
			if(s>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++)b[i]=a[i+1]-a[i];
	for(long long i=1;i<=n;i++)
	    for(long long j=i;j<=n;j++){
	    	s=0;
	    	for(long long l=i;l<j;l++)s+=b[l]*(l-i+1);
	    	if(s<=m)ans=max(ans,j-i+1);
		}
	cout<<ans;
}