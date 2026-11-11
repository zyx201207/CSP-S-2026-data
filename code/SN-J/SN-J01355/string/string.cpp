#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct node{
	int cnt;
	char c;
}a[200000 + 7];
int sz = 0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].cnt >> a[i].c;
	}
	int st = 1;
	int ed = n;
	int ans = 0;
	while (st <= ed){
		if(a[st].c != a[ed].c){
			if(a[st].cnt == a[ed].cnt){
				ans += a[ed].cnt;
				st++;
				ed--; 
				
			}else{
				int x = min(a[st].cnt,a[ed].cnt);
				ans+=x;
				if(a[st].cnt != x){
					a[st].cnt = a[st].cnt-x;
					ed--;
				}else{
					st++;
					a[ed].cnt = a[ed].cnt-x;
				}
			}
		}else{
			if(a[st].cnt == a[ed].cnt){
				st++;
				ed--; 
			}else{
				int x = min(a[st].cnt,a[ed].cnt);
				if(a[st].cnt != x){
					a[st].cnt = a[st].cnt-x;
					ed--;
				}else{
					st++;
					a[ed].cnt = a[ed].cnt-x;
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
