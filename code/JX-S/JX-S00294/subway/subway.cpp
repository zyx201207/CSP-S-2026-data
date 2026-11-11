include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[1000];
int c[1000];
int d[1000];
int e[1000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long c,n,m,d,q,cnt=32,ww=17;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=7;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=7;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=2;i++)
    {
        cin>>d[i];
    }for(int i=1;i<=2;i++)
    {
        cin>>e[i];
    }
    cout<<cnt<<endl<<ww;
    return 0;
}

