#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;
ll n,m,a[N],p2[31];
string s[N];
bool vis[30],ca[N];
void zhuan(ll i){
	s[i]=" ";
	ll t=a[i];
	while(t){
		s[i]+=(t%2+'0');
		t/=2;
	}
	while(s[i].size()<31) s[i]+='0';
	return;
}
int main(){
	fastio;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p2[0]=1;
	for(ll i=1;i<=30;i++) p2[i]=p2[i-1]*2;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		zhuan(i);
	}
	ll i;
	for(i=30;i>=1;i--){
		ll t=0;
		for(ll j=1;j<=n;j++){
			if(s[j][i]=='1') t++;
		}
		if(t>=m) break;
	}
	for(ll j=1;j<=n;j++){
		if(s[j][i]=='1') ca[j]=true;
	}
	vis[i]=true;
	for(;i>=1;i--){
		ll t=0;
		for(ll j=1;j<=n;j++){
			if(ca[j]){
				if(s[j][i]=='1') t++;
			}
		}
		if(t>=m){
			for(ll j=1;j<=n;j++){
				if(s[j][i]!='1') ca[j]=false;
			}
			vis[i]=true;
		}
	}
	ll ans=0;
	for(ll i=1;i<=30;i++){
		ans+=p2[i-1]*vis[i];
	}
	cout<<ans;
	return 0;
}
