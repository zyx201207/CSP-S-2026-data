#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stt{
	ll x;char c;
}a[200200];
ll n,s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	ll l=1,r=n;
	while(l<r){
		ll p=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c){
			s+=p;
		}
		a[l].x-=p,a[r].x-=p;
		if(!a[l].x)l++;
		if(!a[r].x)r--;
	}
	cout<<s<<"\n";
}
