#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	char i1 = s1[2],i2 = s2[2];
	//cout << i1<<i2;
	if(c1 == c2) cout << 1; //Í¬Ò»½ì³µÏá 
	else{
		cout << "0000";
		return 0;
	}
	if(s1[0] + s1[1] == s2[0] + s2[1]) cout << 1;
	else{
		cout <<"000";
		return 0;
	}
	if((i1 <= 'C' && i2 <='C') || (i1 > 'C' && i2 > 'C')) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if(i1+1 == i2 || i2 + 1 == i1){
		cout <<1;
	}else{
		cout << 0;
	}
	return 0;
}
