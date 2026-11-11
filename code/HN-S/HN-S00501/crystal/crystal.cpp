#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
bool js(long long x){
	long long cs=0,k=0;
	for(long long i=1;i<=x;i++){
		cs+=a[x]-a[i];
		if(cs>m)return false;
		k++;
	}
	ans=max(ans,k);
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<r){
		long long zhong=(l+r)/2;
		if(js(zhong)){
			l=zhong+1;
		}else{
			r=zhong-1;
		}
	}
	cout<<ans;
	return 0;
} 
