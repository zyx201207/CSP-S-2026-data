#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int n;
int ans;
struct r{
	int x;
	char c;
}s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> s[i].x >> s[i].c;
	}
	int l = 1 ,r = n;
	while(l < r){
		if(s[l].c == s[r].c){
			if(s[l].x  == s[r].x){
				r--,l++;
			}else{
				if(s[l].x < s[r].x){
					s[r].x -= s[l].x;
					l ++;
				}else{
					s[l].x -= s[r].x;
					r --;
				}
			}
		}else{
			if(s[l].x  == s[r].x){
				ans += s[l].x ;
				r--,l++;
			}else{
				if(s[l].x < s[r].x){
					ans += s[l].x;
					s[r].x -= s[l].x;
					l ++;
				}else{
					ans += s[r].x;
					s[l].x -= s[r].x;
					r --;
				}
			}
		}
//		cout << l <<' ' << r << endl;
	}
	cout << ans;
	return 0;
}
