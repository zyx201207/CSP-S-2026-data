#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],s=0,f=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s=max(s,a[i]);
    }
    if(m==1)
    {
        cout<<s<<endl;
        return 0;
    }
    int x=0;
    while(1==1)
    {
        int t=1;
        for(int i=1;i<=n;i++)
        {
            b[i]+=(a[i]%2)*pow(10,x);
            if(a[i]%2!=1)
            {
                t=0;
            }
            a[i]/=2;
        }
        s/=2;
        if(t!=0)
        {
            f+=pow(2,x);
        }
        if(s==0)
        {
            break;
        }
        x++;
    }
    if(n==m)
    {
        cout<<f<<endl;
        return 0;
    }
    else
    {
        cout<<"0"<<endl;
        return 0;
    }
}
