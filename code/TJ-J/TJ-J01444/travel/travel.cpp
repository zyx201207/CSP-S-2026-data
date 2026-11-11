#include<bits/stdc++.h>
using namespace std;
bool a1, a2, a3, a4;
bool sd1, sd2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)a1=1;
	else a1=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])a2=1;
	else a2=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')sd1=1;
	else sd1=0;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')sd2=1;
	else sd2=0;
	if(sd1==sd2)a3=1;
	else a3=0;
	int mx = max((int)(s1[2]), (int)(s2[2]));
	int mn = min((int)(s1[2]), (int)(s2[2]));
	if(mx-mn==1)a4=1;
	else a4=0;
	cout << (int)a1 << (int)(a1&&a2) << (int)(a1&&a2&&a3) << (int)(a1&&a2&&a3&&a4) << endl;
	return 0;
}
