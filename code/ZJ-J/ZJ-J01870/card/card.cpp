#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[200001],c[200001],ans[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		
    }
    for(int i=1;i<=m;i++) c[a[i]]=c[a[i]-1]+b[a[i]];
    for(int i=1;i<=m;i++)
    {
    	cout<<c[a[i]]-c[1]+1<<" ";
	}
	return 0;
}