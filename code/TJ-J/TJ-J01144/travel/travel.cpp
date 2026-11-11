#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1=10*(s1[0]-'0')+s1[1]-'0',a2=10*(s2[0]-'0')+s2[1]-'0';
	char b1=s1[2],b2=s2[2];
	if(c1!=c2) cout << "0000";
	else{
		cout << "1";
		if(a1!=a2) cout << "000";
		else{
			cout << "1";
			if( ! ( ( (b1<='C') && (b2<='C') ) || ( (b1>='D') && (b2>='D') ) ) ) cout << "00";
			else{
				cout << "1";
				if( ! ( ( (b1>='D') && (b2>='D')  ) || ( (b1<='B') && (b2<='B') ) || ( (b1>='B') && (b2>='B') ) ) ) cout << "0";
				else{
					cout << "1";
				}
			}
		}
	}
	return 0;
} 
