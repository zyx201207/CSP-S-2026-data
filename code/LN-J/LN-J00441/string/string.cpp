#include<bits/stdc++.h>
using namespace std;
bool ish;
const int N =2e9+5;
char str[N];
typedef long long ll;
ll sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(ll j=0;j<n;j++){
		int a;char c;
		cin>>a>>c;
		for(ll i=sum;i<a+sum;i++){
			str[i]=c;
		}
		sum+=a;
	}
	ll num=sum;
	ll t=0;
	for(ll i=0;i<num/2;i++){
		if(str[i]==str[sum-1-i])t++;
	}
	if(t==num/2)ish=true;
	else ish=false;
	ll ans=0;
	if(!ish){
		for(ll i=0;i<num/2;i++){
			if(str[i]!=str[sum-1-i]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
