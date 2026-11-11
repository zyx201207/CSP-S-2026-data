#include<bits/stdc++.h>
using namespace std;

struct Node{
	string c, s;
}a[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 2; i++) cin >> a[i].c >> a[i].s;
	if(a[1].c != a[2].c){
			cout << "0000" << endl;
			return 0;
	}else{
			cout << '1';
	}
	
	if (a[1].s[0] == a[2].s[0] && a[1].s[1] == a[2].s[1])
		cout << '1';
	
	else{
		cout << "000" << endl;
		return 0;
	}
	if (a[1].s[2] == 'A' && (a[2].s[2] == 'B' || a[2].s[2] == 'C'))
		cout << '1';
	else if(a[1].s[2] == 'B' && (a[2].s[2] == 'A' || a[2].s[2] == 'C'))
		cout << '1';
	else if(a[1].s[2] == 'C' && (a[2].s[2] == 'B' || a[2].s[2] == 'A'))
		cout << '1';
	else if ((a[1].s[2] == 'D' && a[2].s[2] == 'F') || (a[2].s[1] == 'F' && a[2].s[2] == 'D'))
		cout << '1';
	else{
		cout << "00" << endl;
		return 0;
	}
	
	if (a[1].s[2] == 'A' && a[2].s[2] == 'B') cout << '1';
	else if (a[1].s[2] == 'B' && (a[2].s[2] == 'A' || a[2].s[2] == 'C')) cout << '1';
	else if (a[1].s[2] == 'C' && a[2].s[2] == 'B') cout << '1';
	else if (a[1].s[2] == 'D' && a[2].s[2] == 'F') cout << '1';
	else if (a[1].s[2] == 'F' && a[2].s[2] == 'D') cout << '1';
	else cout << '0';
	return 0;
}
