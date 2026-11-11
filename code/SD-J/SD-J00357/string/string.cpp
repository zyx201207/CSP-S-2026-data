#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using ll = long long;
ll n, ans = 0, sum = 0;
struct node{
	ll len;
	char c;
}a[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].len>>a[i].c;
		sum += a[i].len;
	}
	ll l = 0, r = sum-1, lid = 0, rid = n-1;
	ll mid = l + r - 1 >> 1;
	ll red = 0;
	if((l+r) % 2 == 0) red = mid+2;
	else red = mid+1;
	while(l < mid || r > red){
		l += a[lid].len;
		l = min(l, mid);
		char lc = a[lid].c;
		ll rto = n - 1 - l;
		if((l+r) % 2 == 0) rto = max(rto, red);
		else rto = max(rto, red);
		
		while(r > rto){
			int rc = a[rid].c;
//			cout<<lid<<' '<<rid<<' '<<l<<' '<<r<<endl;
			if(r - a[rid].len < rto){
//				cout<<r<<' '<<rto<<' '<<rid<<' '<<a[rid].len<<endl;
//				cout<<"special\n";
				int diff = r - rto;
				a[rid].len -= diff; 
				r = rto;
				if(rc != lc) ans += diff;
				break;
			}
			else{
//				cout<<"common\n";
				r -= a[rid].len;
				if(lc != rc){
					ans += a[rid].len;	
				}
				rid--;
			}
		}
		lid++;
	}
	cout<<ans;
	return 0;
}
//fc.exe string.out string4.ans
/*
3
1 a
3 b
2 c

2
*/
