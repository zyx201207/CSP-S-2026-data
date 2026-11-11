#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
vector<ll> c;
vector<char> a;
ll n,k,j,bd;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		c.push_back(x);
		a.push_back(y);
	}j=a.size()-1;
	while(k<j){
		ll minn=min(c[k],c[j]);
		if(a[k]!=a[j]){
			bd+=minn;	
		}
		c[k]-=minn;
		c[j]-=minn;
		if(!c[k])k++;
		if(!c[j])j--;
	}
	cout<<bd;
}
