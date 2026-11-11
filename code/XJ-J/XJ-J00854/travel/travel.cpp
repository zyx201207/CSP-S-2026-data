#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char s1a[5],s2a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0;i<3;i++)
	{
		s1a[i] = s1[i];
		s2a[i] = s2[i];
	}
	if(c1 == c2) 
		cout << 1;//A
	else 
	{
		cout << "0000";
		return 0;
	}
	
	if(s1a[0] == s2a[0] && s1a[1] == s2a[1])//B
		cout << 1;
	else
	{
		cout << "000"; 
		return 0;
	} 
		
	if(s1a[2] <= 'C' && s2a[2] <= 'C')//C
	{
		cout << 1;
	}
	else if(s1a[2] >= 'D' && s2a[2] >= 'D')//D
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}

	if(s1a[2]-s2a[2] < 2)
		cout << 1;
	else 
		cout << '0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}