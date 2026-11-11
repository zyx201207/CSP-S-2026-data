#include<bits/stdc++.h>
using namespace std;
string c2,c4;
int c1,c3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 != c3){//车厢特判 
		cout << "0000";
		return 0;
	}
	cout << 1;
	int p1 = (c2[0] - '0') * 10 + (c2[1] - '0'),p2 = (c4[0] - '0') * 10 + (c4[1] - '0');
	if(p1 != p2){//排数特判 (c2[0] != c4[0]) || (c2[1] != c4[1])
		cout << "000";
		return 0; 
	}
	cout << 1;
	int z1 = c2[2] - 'A',z2 = c4[2] - 'A';
	if((z1 > 2) && (z2 > 2)){
		cout << "11";
		return 0;
	}
	if((z1 <= 2) && (z2 <= 2))
	{
		cout << 1;
		if(z1 + z2 != 2) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << "00";
	return 0; 
}
