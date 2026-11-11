#include<bits/stdc++.h>
using namespace std;
long long n,a[500003],b[500003],m,h,c[500003],f[500003],ans2;
long long ans=1,k=0,d,ans0=1,u;
int eq(long long c[]){
	long long t=b[2];
	for(long long i=2;i<=n;i++)
	if(c[i]!=t)
	return 1;
	return 0;
}
void solve(){
	for(long long i=1;i<=n;i++){
		k=0;
		ans0=1;
		for(long long j=i+1;j<=n;j++){ 
		    k+=b[j]*(j-i);
		    if(k>m)
		    break;
			ans0++;
	    }
	    ans=max(ans,ans0);
	    if(ans+i>n+3)
	    break;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	b[i]=a[i]-a[i-1];
	b[1]=0;
    if(!eq(b)&&n>10000){
    	for(long long i=2;i<=n;i++){
    	k+=(i-1)*b[2];
    	if(k>m)
    	break;
    	ans++;
        }
	}
	else
	solve();
	cout<<ans;
	return 0;
} 
