#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],js=1;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    b[a[n]]=n;
    for(int i=1;i<=m;i++)
        if(i!=a[n])
            b[i]=b[i]+2-i;
    for(int i=1;i<=m;i++) cout<<b[i]<<' ';

	return 0;
}
