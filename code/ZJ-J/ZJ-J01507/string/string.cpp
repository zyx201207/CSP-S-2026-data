#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll lens[200005],al;
char ves[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;string a="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lens[i]>>ves[i];
		al+=lens[i];
	}
	ll mx=al/2;
	ll ans=0;
	ll ks=0,ke=0;
	ll ns=0,ne=0;
	for(ll i=0;i<mx;i++){
		ll jump=min(lens[ks]-ns,min(lens[n-ke-1]-ne,mx-i));
		if(ves[n-ke-1]!=ves[ks]) ans+=jump; 
		ns+=jump; ne+=jump; i+=jump-1;
		if(ns==lens[ks]){
			ks++;ns=0;
		}if(ne==lens[n-ke-1]){
			ke++;ne=0;
		}
	}
	cout<<ans;
	return 0;
}

