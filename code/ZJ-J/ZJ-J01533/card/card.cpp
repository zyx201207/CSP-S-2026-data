#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,a[N],st[N];
vector<int>v;
int main()
{
	freeopen("card.in","r",stdin);
	freeopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	int T=n;
	while(T--)
	{
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<v.size();j++)
			{
				if(a[i]==v[j])
				{
					v.erase(v.begin()+j,v.end());
				}
			}
			v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
			st[v[i]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<st[i]<<" ";
	return 0;
 } 
