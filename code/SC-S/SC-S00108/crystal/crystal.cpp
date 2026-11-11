#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m;
ll a[N],b[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=5000){
    	sort(a+1,a+1+n);
    	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			ll num=j-i+1;
    			ll cnt=b[j]-b[i-1];
    			ll all=a[j]*num;
    			if(all-cnt<=m)ans=max(ans,num);
			}
		}
		cout<<ans;
	}
	else {
		ll c=abs(a[2]-a[1]);
		ll num=1;
		ll cnt=0;
		while(cnt<=m){
			cnt+=num*c;
			num++;
		}
		cout<<num-1;
	}
	return 0;
}