#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string strRa,strRb,strXa,strXb; 
int main() {
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> strRa >> strRb >> strXa >> strXb;
	if(strRa == strXa) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	string rb = "",xb = "";
	rb += strRb[0] + strRb[1];
	xb += strXb[0] + strXb[1];
	if(rb == xb) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	char cr = strRb[2],cx = strXb[2];
	if((cr == 'A' || cr == 'B' || cr == 'C') && (cx == 'A' || cx == 'B' || cx == 'C')) cout << 1;
	else if((cr == 'E' || cr == 'F') && (cx == 'E' || cx == 'F')) cout << 1;
	else {
		cout << "00";
		return 0; 
	}
	if(cr + 1 == cx || cx + 1 == cr) cout << 1;
	else cout << 0;
	return 0;
}

