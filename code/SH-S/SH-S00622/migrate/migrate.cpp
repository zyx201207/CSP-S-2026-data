#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000001],ans,cnt1,cnt2=1e7;
int f(int m,int b,int z){
	ll sum=0;
	if((x[m+1]-x[m])<=z&&(x[b]-x[m+1])<=z)sum++;
	if((x[b-1]-x[m])<=z&&(x[b]-x[b-1])<=z)sum++;
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll g=1;g<=t;g++){
		cin>>n>>d;
		ll r=1e8;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			if(i>=2){
				cnt1=max(cnt1,x[i]-x[i-1]);
				cnt2=min(cnt2,x[i]-x[i-1]);
			}
		} 
		for(ll i=1;i<=n;i++){
			ll y=x[i]-x[i-1];
			if(y>d)r=min(r,i);
		}
		if(r==0)r=n;
		if(r<4){
			cout<<0;
			return 0;
		}if(cnt1==cnt2){
			if(cnt1==d||(d/cnt1)>2)cout<<0;
			else cout<<n-3;
		}
		else{
			for(ll i=1;i<=r-3;i++)
				if(f(i,i+3,d)==2)ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
} 
