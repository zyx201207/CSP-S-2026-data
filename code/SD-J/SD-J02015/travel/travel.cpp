#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2,s3,s4;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	else 
	{
		int ok1=0;
		char aa = s2[2],bb = s4[2];
		for(int i=0;i<=1;++i)
		{
			if(s2[i]!=s4[i]) ok1=1;
			
		}
		
		if(ok1)
		{
			cout<<"1000";
			return 0;
		}
		else 
		{
			if(aa=='D'&&bb=='C'||aa=='C'&&bb=='D')
			{
				cout<<"1100";
				return 0; 
			}
			else
			{
				int aaa=aa-'A',bbb=bb-'A';
				if(aaa<=2&&bbb<=2||aaa>2&&bbb>2)
				{
					if(abs(aaa-bbb)==1)
					{
						cout<<"1111";
						return 0;
					}
					else
					{
						cout<<"1110";
						return 0;
					}
				}
				else
				{
					cout<<"1100";
				}
			}
		}
	}
	return 0;
}
