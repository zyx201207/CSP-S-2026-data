#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
struct node{
	int len;
	char c;
}s[N];
int ans , L_left , R_left , n , l , r;
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>s[i].len>>s[i].c;
	}
	l = 1;
	r = n;
	while(l < r){
		int lenn = min(s[l].len , s[r].len);
		if(s[l].c != s[r].c){
			ans += lenn;
		}
		s[l].len -= lenn;
		s[r].len -= lenn;
		if(s[l].len == 0ll){
			l++;
		}
		if(s[r].len == 0ll){
			r--;
		}
	}
	cout<<ans<<endl;
}
