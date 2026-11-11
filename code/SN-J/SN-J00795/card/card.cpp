//姓名：高梓宸    学校：西安辅轮中学    SN-J00795 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	int a;
	cin>>n>>m;
	int st[500005]={},top=0;
	for(int i=0;i=n;i++)
	{
		cin>>a;
		for(int j=0;j<i;j++)
		{
			if(a==st[j])
			{
				for(int k=j;k<i;k++)
				{
					top--;
				}
			}
		}
		st[top++]=a;
	}
	for(int i=0;i<top;i++)
	{
		cout<<st[i];
	}
	return 0;
}
