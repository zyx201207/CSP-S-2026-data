#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+100;
struct ls{
	ll l;
	char c;
};
ll n;
ls str[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>str[i].l>>str[i].c;
	}
	ll ans=0;
	for(ll i=1,j=n;i<j;){
		ll t=min(str[i].l,str[j].l);
		str[i].l-=t;str[j].l-=t;
		if(str[i].c!=str[j].c){
			ans+=t;
		}
		if(str[i].l==0) i++;
		if(str[j].l==0) j--;
	}
	cout<<ans;
	return 0;
}
