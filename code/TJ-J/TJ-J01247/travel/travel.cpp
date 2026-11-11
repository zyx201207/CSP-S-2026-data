#include <bits/stdc++.h>
using namespace std;
int main()
{ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string s[18] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"};
	string w[5] = {"A","B","C","D","F"};
	int x=0,y=0,z=0,o=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		x = 1;
		for(int i = 0;i < 18;i++)
		{
			for(int j = 0;j < 5;j++)
			{
				if((s1 == s[i] + w[j] && s2 == s[i] + w[j+1] && (s[j] != "C" && s[j+1] != "D"))||(s1 == s[i] + w[j] && s2 == s[i] + w[j-1 ]&& (s[j] != "D" && s[j-1] != "C"))) 
				{
					y = 1;
					z = 1;
					o = 1;
				}
				if((s1 == s[i] + "A" || s1 == s[i] + "B" || s1 == s[i] + "C") &&  (s2 == s[i] + "A" || s2 == s[i] + "B" || s2 == s[i] + "C"))
				{
					z = 1;
				}
				
			}
			
		}
	
	}
	cout << x << y << z << o;
	return 0;
}	
	
	

