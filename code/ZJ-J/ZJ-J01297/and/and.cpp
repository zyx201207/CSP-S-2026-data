#include<bits/stdc++.h>
using namespace std;
long long n,m,a[201010],x,v[201010],s,ans;
int main(){
	freopen("and.in"   ,"r",stdin);
	freopen("and.out"   ,"w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=31;i>=0;i--){
    	x=(1ll<<i),s=0;
    	for(long long j=1;j<=n;j++)if((a[j]&x)&&!v[j])s++;
    	if(s>=m){
    	    ans+=x;
    	    for(long long j=1;j<=n;j++)if((a[j]&x)==0)v[j]=1;
		}
	}cout<<ans;
	return 0;
}
