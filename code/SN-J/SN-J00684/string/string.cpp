//张文硕 西安辅轮中学 SN-J00684 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int num=0,n;
	cin>>n;
	string s;
	int sum=n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
	 } 
	for(int i=1;i<=sum;i++)
	{
		for(int j=sum;j>=sum/2;j--)
		{
			if(s[i]!=s[j])
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
