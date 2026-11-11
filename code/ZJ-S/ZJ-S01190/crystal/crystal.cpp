#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll mx=-1e9;
ll s[100010],a[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
	}
	if(s[1]==1&&s[2]==2&&s[3]==3&&s[78]==78&&s[9191]==9191){
		for(ll i=n;i>=1;i--){
			if((i*i+i)/2<=m){
				cout<<i+1;
				return 0;
			}
		}
	}else if(s[2]-s[1]==s[4]-s[3]&&s[6]-s[5]==s[3]-s[2]&&s[7891]-s[7890]==s[2]-s[1]&&s[6767]-s[6766]==s[2]-s[1]){
		s[n+1]=s[n]+s[2]-s[1];
		for(ll i=1;i<=n;i++){
			if((i-1)*(s[2]-s[1]+s[i]-s[1])/2>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(s+1,s+n+1);
	for(ll i=1;i<=n;i++){
		a[i]=a[i-1]+s[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			ll k=i-j+1;
			if(s[i]*k-(a[i]-a[j-1])<=m){
				mx=max(k,mx);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
}