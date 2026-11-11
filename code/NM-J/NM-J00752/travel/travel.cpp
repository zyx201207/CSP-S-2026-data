#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	// 02 01C 02 01D
	//02 01C 02 01A
	int c1,c2,s1,s2,s=4,i;
	char s11,s22;
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(c1!=c2)cout<<0000;
	if(c1==c2)
	{
		cout<<1;
		s--;
		if(s1==s2)
		{
			cout<<1;
			s--;
			
			if(s11=='A'&&s22=='B'||s11=='A'&&s22=='C'||s11=='B'&&s22=='A'||s11=='B'&&s22=='C'||s11=='C'&&s22=='B'||s11=='C'&&s22=='A'||s11=='D'&&s22=='E'||s11=='E'&&s22=='D')
			{
				cout<<1;
				s--;
				if(s11=='A'&&s22=='B'||s11=='B'&&s22=='A'||s11=='D'&&s22=='E'||s11=='E'&&s22=='D'||s11=='C'&&s22=='B'||s11=='B'&&s22=='C')
				{
					cout<<1;
					s--;
				}
				
			}
			
		}
		
	}
	for(i=1;i<=s;i++)
	{
		cout<<0;
	}
	
	
	return 0;
}
