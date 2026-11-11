#include<iostream>
#include<set>
using namespace std;
int a[1000100];
int s[1000100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	int n,m;
	cin>>n>>m;
	set<int> st;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		st.clear();
		for(int j=i;j<=n;j++)
		{
			if(st.count(a[j])==0) st.insert(a[j]);
			else
			{
				st.clear();
				st.insert(a[j]);
			}
		}
		for(int k=1;k<=m;k++)
		{
			if(st.count(k)!=0) s[k]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
