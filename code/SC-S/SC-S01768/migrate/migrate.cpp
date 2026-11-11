#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],con[2000005]={0};
unsigned long long d;
void solv1(){
	long long ans=0;
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<n;j++){
			if(d>=a[j]-a[i] and d<a[j+1]-a[i]){
				for(long long k=j+1;k<=n;k++){
					if(d>=a[k]-a[j] and d>=a[k]-a[j-1] and d<a[k]-a[j-2]) ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
void solv2(){
	long long ch=a[2]-a[1],ans=0;
	d/=ch;
	if(d<=1) ans=0;
	else {
		ans=n-2*d+1;
		if(ans<0) ans=0;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>a[i];
		if(c<=10) solv1();
		else if(c<=12) solv2();
	}
	return 0;
}