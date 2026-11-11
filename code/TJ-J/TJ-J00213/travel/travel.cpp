//travel
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int che1,che2;
	char zuo1[3],zuo2[3];
	cin >> che1 >> zuo1 >> che2 >> zuo2;
	if (che1 != che2) cout << "0000";
	else 
	{
		cout << "1";
		if ((zuo1[0] != zuo2[0]) || (zuo1[1] != zuo2[1])) cout << "000";
		else {
		cout << "1";
		if (((zuo1[2] == 'A') || (zuo1 [2] == 'B') || (zuo1[2] == 'C')) && ((zuo2[2] == 'A') || (zuo2 [2] == 'B') || (zuo2[2] == 'C')) ) 
		{
			cout << "1";
			if ((zuo1[2] == 'A') && (zuo2[2] == 'B')) cout <<"1";
			else if ((zuo1[2] == 'B') && ((zuo2[2] == 'A') || (zuo2[2] == 'C'))) cout <<"1";
			else if ((zuo1[2] == 'C') && ((zuo2[2] == 'B'))) cout <<"1";
			else cout << 0;
		}
		else if(((zuo1[2] == 'D') || (zuo1[2] == 'F')) && ((zuo2[2] == 'D') || (zuo2[2] == 'F'))) cout << "11";
		else cout << "00";
	}
}
	//cout << che1 << " " << che2 << " " << zuo1[0] << " " << zuo2[0] << endl;
	return 0;	
} 
