#include<bits/stdc++.h>
#define ll long long
//rp++
using namespace std;

string a, b, c ,d, ans;
int cx1, cx2, ph1, ph2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	for(int i = 0;i < a.size();i ++)
		cx1 = cx1 * 10 + (a[i] - '0');
	for(int i = 0;i < c.size();i ++)
		cx2 = cx2 * 10 + (c[i] - '0');
	for(int i = 0;i < b.size() - 1;i ++)
		ph1 = ph1 * 10 + (b[i] - '0');
	for(int i = 0;i < d.size() - 1;i ++)
		ph2 = ph2 * 10 + (d[i] - '0');
	char zw1 = b[b.size() - 1], zw2 = d[d.size() - 1];
	if(cx1 ==cx2){
		ans += '1';
	} else {
		ans += "0000";
		cout << ans;
		return 0;
	}
	if(ph1 == ph2){
		ans += '1';
	} else {
		ans += "000";
		cout << ans;
		return 0;
	}
	if((zw1 <= 'C' && zw1 >= 'A' && zw2 <= 'C' && zw2 >= 'A') || (zw1 <= 'F' && zw1 >= 'D' && zw2 <= 'F' && zw2 >= 'D')){
		ans += '1';
	} else {
		ans += "00";
		cout << ans;
		return 0;
	}
	if((zw1 == 'A' && zw2 == 'B') || (zw1 == 'B' && zw2 == 'C') ||(zw1 == 'D' && zw2 == 'F')){
		ans += '1';
	} else {
		ans += '0';
	}
	cout << ans;
	return 0;
}
