#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,siz,ans;
ll a[1000005];
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
	}
	ll l=0,r=a[n];
	ll nl=1,nr=n,pos=0;
	while(l<=r){
		bool flag=0;
		if(a[nl]-l>r-a[nr]){
			pos=r-a[nr];
			flag=1;
		}else{
			pos=a[nl]-l;
			flag=0;
		}	
		l+=pos;r-=pos;
		if(l>r) break;
		if(c[nl]!=c[nr]){
			ans+=pos;
		}//cout<<(c[nl]!=c[nr])<<flag<<' '<<l<<' '<<r<<' '<<' '<<pos<<'\n';
		if(flag)nr--;
		else nl++;	
		//cout<<nl<<' '<<nr<<'\n';
	}
	cout<<ans;
}
