#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin >> c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout << '1';
	}
	else
	{
		cout << "0000";
		return 0;
	}
	char s1num,s1nnum;
	char s2num,s2nnum;
	for (int i =0;i < s1.size();i++)
	{
		if (s1[i]>='0'&&s1[i]<='9')
		{
			s1nnum+=s1[i];
			s2nnum+=s2[i];
		}
		if (s1[i]>='A' && s1[i] <= 'Z')
		{
			s1num=s1[i];
			s2num=s2[i];
		}
	}
	if (s1nnum==s2nnum) cout << '1';
	else cout << '0';
	if (s1num<='C'&& s2num<='C') cout << '1';
	else cout << '0';
	if (s1num-'0'+1==s2num-'0'||s2num-'0'+1==s1num-'0')
	{
		cout << '1';
		
	}
	else
	{
		cout << '0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}