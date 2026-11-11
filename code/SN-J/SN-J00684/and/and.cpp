//张文硕 西安辅轮中学 SN-J00684 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and,in","r",stdin);
	freopen("and,out","w",stdout);
	int num=0;
	int n,m,a[2000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(num>=0)
		num=a[i]&a[i+1];
	}
	cout<<num;
	return 0;
 } 
