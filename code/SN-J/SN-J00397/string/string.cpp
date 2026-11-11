#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ull n, cnt = 0;
string s = " ";

struct node{
	ull a;
	char c;
}x[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(ull i=1;i<=n;i++){
		cin >> x[i].a >> x[i].c;
		/*
		for(ull j=1;j<=a;j++){
			s = s + c;
		}
		*/
	}
	for(ull i=n-1;i>0;i--){
		if(x[i].c == x[i+1].c){
			x[i].a += x[i+1].a;
			x[i+1].a = 0;
		}
	}
	for(ull i=1;i<=1;i++){
		if(x[i].c == x[n+1-i].c){
			if(x[i].a >= x[n+1-i].a){
				x[i].a -= x[n+1-i].a;
				x[n+1-i].a = 0;
			} else {
				x[n+1-i].a -= x[i].a;
				x[i].a = 0;
			}
		}
	}
	for(ull i=1;i<=n;i++){
		for(ull j=1;j<=x[i].a;j++){
			s = s + x[i].c;
		}
	}
	ull siz = s.size() - 1;
	//cout << s << " ";
	for(ull i=1;i<=(siz+1)/2;i++){
		if(s[i] != s[siz+1-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
