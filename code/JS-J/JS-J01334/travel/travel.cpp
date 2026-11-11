#include <bits/stdc++.h>
using namespace std;
struct node
{
	char cx1,cx2;
	char n1,n2;
	char w;
}a,b;
bool flag1,flag2,flag3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a.cx1 >> a.cx2 >> a.n1 >> a.n2 >> a.w >> b.cx1 >> b.cx2  >> b.n1 >> b.n2 >> b.w;
//	cout << a.cx1 << " " << a.cx2 << " " << a.n1 << " " << a.n2 << " " << a.w << " " << b.cx1 << " " << b.cx2 << " " << b.n1 << " " << b.n2 << " " << b.w << endl;
	if(a.cx1 == b.cx1 && a.cx2 == b.cx2)
	{
		cout << 1;
		flag1 = 1;
	}
	else cout << 0;
	if(a.n1 == b.n1 && a.n2 == b.n2 && flag1)
	{
		cout << 1;
		flag2 = 1;
	}
	else cout << 0;
	if(((a.w <= 'C' && b.w <= 'C') || (a.w >= 'D' && b.w >= 'D')) && flag2)
	{
		cout << 1;
		flag3 = 1;
	}
	else cout << 0;
	if(abs(a.w - b.w) == 1 && flag3)
	{
		cout << 1;
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
