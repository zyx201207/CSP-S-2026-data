#include<bits/stdc++.h>
using namespace std;

int check(string a,string b)
{
	int fa,fb;
	
	if(a[2] == 'F' || a[2] == 'D')
		fa = 1;
	else
		fa = 0;
	
	if(b[2] == 'F' || b[2] == 'D')
		fb = 1;
	else
		fb = 0;
		 
	return fa == fb;
}

int fok(string a,string b)
{	
	if(a[0] == b[0] && a[1] == b[1])
		if(a[2] == b[2] + 1 || a[2] == b[2] - 1)
			return 1;
	
	int x = (a[0] - '0') * 10 + (a[1] - '0'),y = (b[0] - '0') * 10 + (b[1] - '0');
	 
	if(a[2] == b[2])
		if(x == y + 1 || x == y - 1)
			return 1;
			
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string a,b,x,y;
	
	cin >> a >> b >> x >> y;
	
	if(a == x)
		cout << 1;
	else
		cout << 0;
		
	if(a == x && b[0] == y[0] && b[1] == y[1])
		cout << 1;
	else
		cout << 0;

	if(a == x && b[0] == y[0] && b[1] == y[1] && check(b,y) == 1)
		cout << 1;
	else
		cout << 0;
		
	if(fok(b,y) == 1 && check(b,y) == 1)
		cout << 1;
	else
		cout << 0;
		
	return 0;
}
