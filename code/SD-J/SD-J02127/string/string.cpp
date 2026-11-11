#include<iostream>
#define ll long long
using namespace std;
ll n, sum[200010], ans, hh, tt, now;
char let[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>sum[i]>>let[i];
	hh=1;tt=n;
	while(hh<tt){
		now=min(sum[hh], sum[tt]);
		sum[hh]-=now;sum[tt]-=now;
		if(let[hh]!=let[tt]) ans+=now;
		if(sum[hh]==0) hh++;
		if(sum[tt]==0) tt--;
	}
	cout<<ans;
	return 0;
} 
