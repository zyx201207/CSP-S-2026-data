#include<bits/stdc++.h>
using namespace std;
int n,m,b[300005],a[500005];
queue<int> q;
queue<int> p;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	    int ls[500005],zt[500005];
		for(int j=1;j<i;j++)
        {
            if(a[i]==a[j])
            {
                for(int z=j;z<i;z++)
                {
                    q.push(a[z]);
                }
            }
            b[a[i]]++;
        }
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
    return 0;
}
















