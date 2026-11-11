#include <bits/stdc++.h>
using namespace std;

int id1,l1,id2,l2;
char seat1,seat2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> id1 >> l1;
	cin >> seat1;
	cin >> id2 >> l2;
	cin >> seat2;
	if(id1 == id2)
	{
		cout << "1";
		if(l1 == l2)
		{
			cout << "1";
			if((seat1<='C' && seat2<='C') || (seat1>'C' && seat2>'C'))
			{
				cout << "1";
				if(abs(seat1-seat2) == 1)cout << "1" << endl;
				else cout << "0" << endl;
			}
			else cout << "00" << endl;
		}
		else cout << "000" << endl;
	}
	else cout << "0000" << endl;
	return 0;
}
