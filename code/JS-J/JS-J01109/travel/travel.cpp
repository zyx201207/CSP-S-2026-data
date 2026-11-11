#include<bits/stdc++.h>
#define ll long long 
#define vet vector
using namespace std;

int n1,n2;
string s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2)puts("0000");
	
	else
	{
		int ans[4]={1,0,0,0};
		int x1,x2;
		x1=x2=0;
		int p1,p2;
		
		
		int len1=s1.size(),len2=s2.size();
		for(int i=0;i<len1;i++)
		{
			if(s1[i]>='0' && s1[i]<='9')
			{
				x1=x1*10+s1[i]-'0';
			}
			else p1=s1[i]-'A';
		}
		for(int i=0;i<len2;i++)
		{
			if(s2[i]>='0' && s2[i]<='9')
			{
				x2=x2*10+s2[i]-'0';
			}
			else p2=s2[i]-'A';
		}
//		printf("%d%d%d%d",x1,p1,x2,p2);
	
		if(x1==x2)
		{
			ans[1]=1;
			if((p2<=2 && p1<=2))
			{
				ans[2]=1;
				if(abs(p1-p2)<=1)
				{
					ans[3]=1;
				}
			}
			if(p2>=3 && p1>=3)
			{
				ans[2]=1;
				ans[3]=1;
				
			}
		}
		for(int i=0;i<4;i++)printf("%d",ans[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
