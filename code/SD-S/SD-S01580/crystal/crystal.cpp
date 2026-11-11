#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m,b[500005],s,cnt,star,ans;
map<long long,long long>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b+1,b+n+1);
	star=1;
	for(int i=1;i<=n;i++){
		while(m<(b[i]-b[i-1])*s&&star<i)s--,m+=b[i-1]-b[star],star++;
		if(m>=(b[i]-b[i-1])*s)m-=(b[i]-b[i-1])*s,s++;
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
