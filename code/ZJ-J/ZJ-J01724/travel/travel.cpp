#include<bits/stdc++.h>
using namespace std;
int ans[5];
bool flag=true;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for (int i=1;i<=4;i++)
		ans[i]=0;
	if (c1==c2)
	{
		ans[1]=1;
		for (int i=0;i<2;i++)
			if (s1[i]!=s2[i])
				flag=false;
		if (flag)
		{
			ans[2]=1;
			if ((s1[2]-'A'>=0 and s1[2]-'A'<=2 and s2[2]-'A'>=0 and s2[2]-'A'<=2) or (s1[2]-'D'>=0 and s1[2]-'D'<=2 and s2[2]-'D'>=0 and s2[2]-'D'<=2))
			{
				ans[3]=1;
				if ((abs((s1[2]-'A')-(s2[2]-'A'))==1) or ((s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D')))
					ans[4]=1;
			}
		}
	}
	for (int i=1;i<=4;i++)
		cout<<ans[i];
	cout<<"\n";
	return 0;
} 
