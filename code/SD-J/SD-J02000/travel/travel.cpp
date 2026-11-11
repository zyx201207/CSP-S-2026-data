//travel
#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b)
{
	if(a[2] <= 'C' && a[2] >= 'A')
		if(b[2] <= 'C' && b[2] >= 'A')
			return 1;
	return (a[2] == 'D' || a[2] == 'F') && (b[2] == 'D' || b[2] == 'F');
}
bool ch(string a,string b)
{
	if(a[2] == 'A')
		if(b[2] == 'B') return 1;
	if(a[2] == 'B') return 1;//同侧，必定相邻 
	if(a[2] == 'C')
		if(b[2] == 'B') return 1;
	if(a[2] == 'D') return (b[2] == 'F');
	if(a[2] == 'F') return (b[2] == 'D');
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c[3],s[3]; int f = -1;
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1] == c[2]) f = 0,cout<<1;
	else cout<<0;
	if(f == 0 && s[1][0] == s[2][0] && s[1][1] == s[2][1])
		f = 1,cout<<1;
	else cout<<0;
	if(f == 1 && check(s[1],s[2])) f = 2,cout<<1;
	else cout<<0;
	if(f == 2 && ch(s[1],s[2])) cout<<1;
	else cout<<0;
	return 0;
} 
