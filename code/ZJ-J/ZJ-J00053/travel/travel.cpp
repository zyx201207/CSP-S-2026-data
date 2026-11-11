#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int inf = 1e18;
const int N = 2e5+5;
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
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << (int)(a==c);
	if(a!=c){
		cout << "000";
		return;
	}
	cout << (int)(b[0] == d[0] && b[1] == d[1]) << (int)((b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C')&&(b[0] == d[0] && b[1] == d[1]));
	if(!(b[0] == d[0] && b[1] == d[1])){
		cout << 0;
		return;
	}
	if(b[2] > 'C' && d[2] > 'C'){
		cout << 1;
		return;
	}
	if(b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C'){
		if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'){
			cout << 0;
		}
		else{
			cout << 1;
		}
	}
	else{
		cout << 0;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _ = 1;
//	read(_);
	while(_--)solve();
	return 0;//0^0
}
