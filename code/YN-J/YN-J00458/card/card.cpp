#include <bits/stdc++.h>
using namespace std;
const int N=5e+5+5;
int a[N];
int st[N];
int ans[N];
stack<int>z;
int g=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int t=1;t<=n;t++)
	{
		for(int i=t;i<=n;i++)
		{
			if(st[a[i]]==1)
			{
				while(z.top()!=a[i]){
					st[z.top()]--;
					z.pop();
					g--;
				}
			}
			else{
				z.push(a[i]);
				st[a[i]]++;
				g++;
			}
		}
		while(g!=0){
			ans[z.top()]++;
			z.pop();
			g--;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
