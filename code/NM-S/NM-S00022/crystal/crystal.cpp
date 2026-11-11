#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500010],ans=0,tmp,zz1=n,zz2=n,x=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			tmp=m;
			for(long long j=i;j>=1;j--){
				if(tmp>=(a[i]-a[j])) {
					tmp-=a[i]-a[j];
					ans=max(ans,i-j+1);
				}else break;
			}
		}cout<<ans;
	}else {
		//JUST.IT.DO
		long long j=n;tmp=m;
		for(long long i=n;i>=1;i--){
			for(j;j>=1;j--){
				if(tmp>=(a[i]-a[j])) {
					tmp-=a[i]-a[j];
				}else break;
			}ans=max(ans,i-j);
			tmp+=(a[i]-a[i-1])*(i-j-1);
		}cout<<ans;
	}	 
	return 0;
}
