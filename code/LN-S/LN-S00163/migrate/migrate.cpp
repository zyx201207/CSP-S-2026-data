#include<bits/stdc++.h>
using namespace std;
long long a[10000005];

void tepan(long long h){while(h--){
	long long n,d,ans=0;
	cin>>n>>d;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		}
	if(n<=2){cout<<0;continue;}
	if(abs(a[2]-a[1])>d) {cout<<0;return;}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(a[j]-a[i]>d&&a[j]-a[i]<2*d) ans++;
		}}
		cout<<ans<<endl;}
		return;
		}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
//别忘记取消！！
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
long long c,t;
cin>>c>>t;
tepan(t);
return 0;}
