#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;
int n;
int cnt = 0;
struct node{
	int a;
	string c;
}no[MAXN];
//bao li chu qi ji
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string s;
	for(int i = 1;i <= n;++i){
		cin >> no[i].a >> no[i].c;
		for(int j = 1;j <= no[i].a;++j) s += no[i].c;
	}
	int l = 0,r = s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]) cnt++;
		l++,r--;
	}
	cout << cnt;
	return 0;
} 
