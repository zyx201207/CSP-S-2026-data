#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050],ans[12002002],mo[20050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		ans[a[i]]++;
	}
    for(int i=1;i<=m;i++)cout<<ans[a[i]]<<" ";
    return 0;
}
