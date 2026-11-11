#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	int q1=0,q2=0,q3=0,q4=0,ans1,ans2;
	if(a==b)
	{
		q1=1;
		if(a1[0]==b1[0]&&a1[1]==b1[1])
		{
			q2=1;
			if((a1[2]<='C'&&b1[2]<='C')||(a1[2]>='D'&&b1[2]>='D'))
			{
				q3=1;
				ans1=a1[2];
				ans2=b1[2];
				if(max(ans1,ans2)-min(ans1,ans2)==1) q4=1;
			}
		}
	}
	cout<<q1<<q2<<q3<<q4;
}
