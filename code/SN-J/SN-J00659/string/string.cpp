//zbh   °¿ÏèÖÐÑ§    SN-J00659 
#include<bits/stdc++.h>
using namespace std;
long long n,max_2,sum;
struct op{
	int a;
	char b;
}m[200005];
string u,v;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i].a>>m[i].b;
		for(int j=1;j<=m[i].a;j++)
		{
			u+=m[i].b;
		}
		max_2+=m[i].a;
	}
	for(long long i=max_2-1;i>=0;i--) v+=u[i];
	for(long long i=1;i<=n;i++)
	{
		if(v[i]!=u[i]) sum++;
	}
	//cout<<v<<endl<<u;
	cout<<sum;
	return 0;
}
