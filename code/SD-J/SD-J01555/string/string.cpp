#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,j=0;
char s[200000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char w;
		cin>>x>>w;
		for(ll i=1;i<=x;i++){
			j++;
			s[j]=w;
		}
	}
	ll le=j/2,f=0; 
	for(ll i=1;i<=le;i++){
		if(s[i]!=s[j]){
			f++;
		}
		j--;
	}
	cout<<f;
	return 0;
}

