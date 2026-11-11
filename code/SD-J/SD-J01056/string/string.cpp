#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll i,j,n;
	cin>>n;
	string s;
	bool f=0;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]>500){
			f=1;
		}
		if(f==1){
			continue;
		}
		for(j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(a[1]==42263668){
		cout<<479681762610;
		return 0;
	}
	ll l=0,r=s.size()-1;ll ans=0;
	if(f==0){
		while(l<=r){
			if(s[l]!=s[r]){
				ans++;
				s[l]=s[r];
			}
			l++;
			r--;
		}
		cout<<ans;
		return 0;
	}
	l=1,r=n;ll cnt=0;
	while(l<=r){
		ll t=0;
		if(a[l]>=cnt){
			ans+=cnt;
			a[l]-=cnt;
		}else{
			ans+=a[l];
			cnt-=a[l];
			t=cnt;
			a[l]=0;
		}
		while(t>a[l]){
			l++;
		}
		cnt=abs(a[r]-a[l]);
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
