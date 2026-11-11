#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int a[10] = {0};
string c1,s1,c2,s2;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	int cpw=0,mpx=0;
	if(s1[2] <= 'C' && s2[2] <= 'C')
	{
		cpw = 1;
		if(s1[2] >= 'A'&& s1[2] <= 'B' && s2[2] >= 'A'&& s2[2] <= 'B')
		{
			mpx = 1;
		}
		if(s1[2] >= 'B'&& s1[2] <= 'C' && s2[2] >= 'B'&& s2[2] <= 'C')
		{
			mpx = 1;
		}
	}
	if(s1[2] >= 'D' && s2[2] >= 'D')
	{
		cpw = 1;
		mpx = 1;
	}
	
	if(c1 == c2)
	{
		a[0] = 1;
	}
	if(a[0] == 1 && s1[1] == s2[1])
	{
		a[1] = 1;
	}
	if(a[1] == 1 && s1[1] == s2[1] && cpw == 1)
	{
		a[2] = 1;
	}
	if(a[2] == 1 && mpx == 1)
	{
		a[3] = 1;
	}
	for(int i = 0;i < 4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
