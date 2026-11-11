#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll a[maxn];
ll n,m,s=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n-m;i++){
		ll num=a[i];
		ll c=1;
		for(ll j=i+1;j<=n;j++){
			if(c>=m){
				break;
			}else{
				c++;
			}
			num=num&a[j];
		}
		s=max(s,num);
	}
	cout<<s;
	return 0;
}