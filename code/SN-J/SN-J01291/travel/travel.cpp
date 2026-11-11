#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int s1_1 = (s1[0] - '0')*10 +(s1[1] - '0');
	int s2_1 = (s2[0] - '0')*10 +(s2[1] - '0');
	if (c1 == c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(s1_1 == s2_1 && c1== c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C') && (s1_1 == s2_1) && (c1 == c2)){
		cout << 1;
	}
	else if (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C') && (s1_1 == s2_1) && (c1 == c2)){
		cout << 1;
	}
	else if (s1[2] == 'C' && (s2[2] == 'B' || s2[2] == 'A') && (s1_1 == s2_1) && (c1 == c2)){
		cout << 1;
	}
	else if (s1[2] == 'D' && s2[2] == 'F'){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if (s1[2] + 1 == s2[2] && (s1[2] + 1 != 'D') && (s1_1 == s2_1) && (c1 == c2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
