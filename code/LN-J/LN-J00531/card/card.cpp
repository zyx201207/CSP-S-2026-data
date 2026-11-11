#include<bits/stdc++.h>
using namespace std;
long long a[500005],a1=0,a2=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,vis[10]={false};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]=='1')
        {
            a1++;
            vis[i]=true;
        }
        if(a[i]=='2')
    }
    if(a1==4)
    {
        for(int i=1;i<=5;i++)
        {
            if(vis[i]==false)
            {
                if(vis[i]==false)
                {
                    cout<<"4 5";
                    return 0;
                }
                cout<<"5 "<<6-i;
            }
        }
    }
    return 0;
}
