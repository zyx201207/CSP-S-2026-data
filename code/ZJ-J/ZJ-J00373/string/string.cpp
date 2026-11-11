#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ma;
ll s[200010];
map<ll,ll> x;
map<ll,char> c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cin>>c[i];
		s[i]=s[i-1]+x[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]<=s[n]/2){
			if(c[i]!=c[n-i+1]){
				ma=ma+min(x[i],x[n-i+1]);
			}
		}
		else break;
	}
	cout<<ma;
	return 0;
}