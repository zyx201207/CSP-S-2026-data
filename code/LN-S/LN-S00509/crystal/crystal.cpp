#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[0]=min(a[2]-a[1],a[1]);
	for(long long i=1;i<=n;i++){
		b[i]=abs(b[i-1]+a[i]);
	}
	long long k=m;
	for(long long i=0;i<=n;i++){
		if(b[i]<=k){
			ans++;
			k-=b[i];
		}
		else{
			break;
		}
	}
	if(ans!=0){
		ans++;
	}
	if(ans>n){
		ans=n;
	}
	cout<<ans<<endl;
	return 0;
}
