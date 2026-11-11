#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a,b,c,d;
	char s1[105],s2[105];
	cin >> c1 >> s1 >> c2 >> s2;
	a=s1[0]*10+s1[1];
	b=s2[0]*10+s2[1];
	c=s1[2];
	d=s2[2];
	if(c1==c2){
		cout << "1";
		if(a==b){
			cout << "1";
			if(c-d<=2||d-c<=2){
				cout << "1";
				if(c-d==1||d-c==1){
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
