#include<iosteam>
using namespace std;


int main(){
	freopen("travel.in","r","std.in");
	freopen("travel.out","w","std.out");
	int c1,c2,n1,n2,x = 0;
	char s1,s2;
	cin >> c1 >> n1 >> s1 >> c2 >> n2 >> s2;
	if(c1 == c2&&(01 < c1&& c1 < 16 ))
		cout << "1";
		if(n1 == n2)
			cout << "1";
			if(s1 <= 'C'&&s2 <= 'C')
				cout << "1";
				if(s1 == 'A'&&s2 == 'B')
					cout << "1";
				else if(s1 == 'B'&&s2 == 'C')
					cout << "1";
				else
					cout << "0";
			else if(s1 > 'C'&& s2 > 'C')
				cout << "11";
			else
				cout << "00";
		else
			cout << "000";
	else
		cout << "0000";
	return 0;
}