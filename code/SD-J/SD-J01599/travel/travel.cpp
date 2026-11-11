#include<bits/stdc++.h>
using namespace std;
/*====================*/

/*====================*/
string s1,s2;
int c1,c2;
int a[4];
/*====================*/
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a[1]=1;
			int k_=s1[2]-'A'+1,k__=s2[2]-'A'+1;
			if((k_<=3&&k__<=3)||(k_>=4&&k__>=4))
			{
				a[2]=1;
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)a[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++)cout<<a[i];
	return 0;
}

