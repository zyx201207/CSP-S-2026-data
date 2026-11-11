#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int cnt=0;
    int w[10005];
    int k[10001];
    int all=0;
    int jihua[10001];
    int a;
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        cin>>k[i];
        int line[i];
    }
    for(int i=1; i<=q; i++)
    {
        cin>>jihua[i];
    }
    int all1,all2;
    for(int j=1; j<q; j++)
    {
        for(int i=1; i<=m; i++)
        {
            if(line[i]==line[i])
                if(i%2!=0)
                {
                    all1=w[i]+k[i+1]+k[i+3];
                    if(i%2==0)
                    {
                        all2=w[i+3]+k[i+3]+w[i+5];
                    }
                }
        }
        all=all1+all2;
        cout<<all;
    }
    return 0;
}
