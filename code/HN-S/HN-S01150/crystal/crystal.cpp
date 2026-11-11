#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[500100],cnt,sum;
bool check(ll x){
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	queue<ll>q;
	ll num=0,maxx=0,len=0;
	for(ll i=1;i<=n;i++){
		while(num>m){
			num=num-(a[i-1]-a[q.front()]);
			q.pop();
			len--;
		}
		maxx=max(maxx,len);
		q.push(i);
		len++;
		num=num+(q.size()-1)*(a[i]-a[i-1]);
	}
	while(num>m){
		num=num-(a[n]-a[q.front()]);
		q.pop();
		len--;
	}
	maxx=max(maxx,len);
	cout<<maxx;
	return 0;
}

