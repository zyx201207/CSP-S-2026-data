#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	a[s1[2]-'A'+1]++;a[s2[2]-'A'+1]++;
	if(a[1]==1&&a[2]==1||a[2]==1&&a[3]==1||a[4]==1&&a[6]==1||a[1]==1&&a[3]==1) cout<<"1";
	else cout<<"0";
	if(a[1]==1&&a[2]==1||a[2]==1&&a[3]==1||a[4]==1&&a[6]==1) cout<<"1";
	else cout<<"0";
	return 0;
}