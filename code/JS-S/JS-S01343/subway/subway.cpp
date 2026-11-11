#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,cnt=0;
    cin>>c>>n>>m>>d>>q;
    int a[m],b[n+1][n+m-4],e[2][n];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    cnt+=c+n+m+d+q+a[0]+a[1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+m;j++)
        {
            cin>>b[i][j];
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>e[i][j];
        }
    }
    if(cnt%2==0) cout<<cnt<<endl<<cnt/2+1;
    else if(cnt%2==1) cout<<cnt<<endl<<cnt/2-1;
    return 0;
}
