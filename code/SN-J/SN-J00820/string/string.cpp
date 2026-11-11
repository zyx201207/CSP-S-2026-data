//白云海 SN-J00820 陕西延安中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,m[100005];
	int a=0,b=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		{
			m[j]=b;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<m[i];
	}
	return 0;
} 
