#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int c[300005];
bool b[300005];
stack<int>st;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<m;i++) b[i]=false;
		int len=0;
		for(int i=k;i<n;i++)
		{
			st.push(a[i]);
			if(b[a[i]]==false) b[a[i]]=true;
			else
			{
				int l=0;
				while(a[l]!=a[i]) l++;
				l=i-l;
				while(l--) st.pop();
				//st.push(a[i]);
			}
		}
		while(st.empty()==false)
		{
			c[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
