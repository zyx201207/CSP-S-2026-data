#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
char r1s,x1s;
int r1zw,x1zw;
bool flag = 1;
int zh(string a)
{
	int ans;
	ans = a[0]*10+a[1];
	return ans;
}
bool tcpd(string a,string b)
{
	return (a[2] == 'A' && (b[2] == 'B' || b[2] == 'C') )|| (a[2] == 'B' && (b[2] == 'A' || b[2] == 'C')) || 
	(a[2] == 'C' && (b[2] == 'B' || b[2] == 'A')) || (a[2] == 'D' && b[2] == 'F') || (a[2] == 'F' && b[2] == 'D');
}
bool xlpd(string a,string b)
{
	if((char)a[2] - (char)b[2] == 1 || (char)a[2] - (char)b[2] == -1)
	return 1;
	else
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	r1s = r2[2];
	x1s = x2[2];
	r1zw = zh(r2);
	x1zw = zh(x2);
	if(r1 == x1) cout << 1;
	else {cout << 0;flag = 0;}
	if(r1zw == x1zw && flag) cout << 1;
	else {cout << 0;flag = 0;}
	if(tcpd(r2,x2) && flag) cout << 1;
	else{cout << 0;flag = 0;}
	if(xlpd(r2,x2) && flag) cout << 1;
	else{cout << 0;flag = 0;}
	return 0;
}
