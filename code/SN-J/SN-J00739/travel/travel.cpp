//谢震寰 西安市第三中学 SN-J00739 
#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin >>c1>>s1>>c2>>s2;
	int i=1;
	if(c1!=c2 || c1=="01" || c1=="16")
	{
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
	}
	else
	{
		a[i]=1;
		i++;
		int t1=int(s1[0]-'0')*10+int(s1[1]-'0');
		int t2=int(s2[0]-'0')*10+int(s2[1]-'0');
		if(t1==t2)
		{
			a[i]=1;
			i++;
			if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || ((s1[2]=='D' && s2[2]>='F') || (s1[2]=='F' && s2[2]=='D')))
			{
				a[i]=1;
				i++;
				if(abs(s1[2]-s2[2])==1)
				{
					a[i]=1;
					i++;
				}
				else
				{
					a[i]==0;
					i++;
				}
			}
			else
			{
				a[i]==0;
				i++;	
			}
		}
		else 
		{
			a[i]==0;
			i++;
		}
	}
	for(int i=1;i<=4;i++) cout <<a[i];
	return 0;
}
