#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int inf = 1e18;
const int N = 2e5+5;
int a[N];
char c[N];
void read(int &x){
	char c = getchar();
	while(c!='-'&&!(c>='0'&&c<='9'))c=getchar();
	int f = 1;
	if(c=='-')f = -1;
	x = 0;
	while((c>='0'&&c<='9')){
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
void readc(char &c){
	c = getchar();
	while(c==' ')c=getchar();
}
void solve(){
	int n;
	read(n);
	for(int i = 1;i <= n;i++){
		read(a[i]);
		readc(c[i]);
	}
	int l = 1,r = n;
	int ans = 0;
	while(l<r){
		if(c[l]==c[r]){
			int t = min(a[l],a[r]);
			a[l]-=t;
			a[r]-=t;
			if(!a[l])l++;
			if(!a[r])r--;
		}
		else{
			int t = min(a[l],a[r]);
			a[l]-=t;
			a[r]-=t;
			ans += t;
			if(!a[l])l++;
			if(!a[r])r--;
		}
	}
	cout << ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _ = 1;
	// read(_);
	while(_--)solve();
	return 0;
}
