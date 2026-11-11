//zbh   °¿ÏèÖÐÑ§    SN-J00659 
#include<bits/stdc++.h>
using namespace std;
string a;
char w;
int m,n;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w;
		a=a+w;
	}
	for(int i=1;i<=m;i++) cout<<n;
	return 0;
}
