#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,san=0,c=0,b=0;
	cin>>n;

	string s,d;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		cin>>d;
		for(int j=1;j<=c;j++)
		{
			s+=d;
			
		}
		b+=c;
		c=0;
		
		
	}
	
		b-=1;
		for(int i=0;i<b/2;i++)
		{
			if(s[i]!=s[b-i])
			{
				san+=1;
			}
			
			
			
			
		}
	cout<<san<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
