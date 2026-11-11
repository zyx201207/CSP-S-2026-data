#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("travel.in","r",stdin);
	feropen("travel.out","w",stdout);
	int n,c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2 ;
	for(int i=1;i<=n;i++)
	{
		if(c1==c2 && s1-'A'/100==s2-'A'/100 && s2-s1<=2 && s1-s2==1 )
		{
			cout << "1111";
		}
		if(c1==c2 &&s1-'A'/100==s2-'A'/100 && s2-s1<=2 )
		{
			cout << "1110";
		}
		if(c1==c2 &&s1-'A'/100==s2-'A'/100 )
		{
			cout << "1100";
		}
		if(c1==c2)
		{
			cout << "1000";
		}
		else
		{
			cout << "0000";
		}
	}
	
	
	
	
	return 1;
}
