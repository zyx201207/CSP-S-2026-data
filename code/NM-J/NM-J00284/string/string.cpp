#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct node{
	int ai;
	bool vis;
	char c;
	int nowl;
}a[N];

ll num;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	int rcnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i].ai >> a[i].c;
		num += a[i].ai;
		rcnt++;
	}
	int lcnt = 1;
	ll ans = 0;
	for(ll l = 0,r = num;;){
		if(lcnt < rcnt){
			ll minn = min(a[lcnt].ai-a[lcnt].nowl,a[rcnt].ai-a[rcnt].nowl);
			a[lcnt].nowl += minn;
			a[rcnt].nowl += minn;
			l += minn,r-= minn;
			if(a[lcnt].c != a[rcnt].c){
				ans += minn;
			}
			if(a[lcnt].ai == a[lcnt].nowl){
				lcnt++; 
			}
			if(a[rcnt].ai == a[rcnt].nowl){
				rcnt--; 
			}
		}else{
			break;
		}	
	}
	cout << ans;
	return 0;
}
