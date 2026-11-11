#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    long long w[500010],a[510][500010],t[510][500010],st[100010],en[100010],ans[100010],k[510];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>st[i]>>en[i];
    }
    for(int i=1;i<=q;i++)
    {
        long long zssj=0;
        long long zhanshu=en[q]-st[q];
        long long zxzs=st[q];
        for(int o=1;o<=n;o++)
        {
            for(int l=1;l<=k[i];l++)
            {
                if(a[o][l]==st[q])
                {
                    zssj+=w[st[q]];
                    zssj+=t[o][l];
                }
                if(a[o][l+1]>en[q])
                {
                    break;
                }
                if(a[o][l+1]==en[q])
                {
                    zssj+=t[o][l+1];
                    zssj+=w[en[q]];
                }
            }
        }
        cout<<zssj<<endl;
    }
    return 0;
}
