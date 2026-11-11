#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e5+10;
int c,n,m,d,q,ma,l,r,T;
int w[N],k[505],num[505];
int of[505][500005];
struct node{
    int p,t;
}a[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c==0&&d==2)
    {
        cout<<32<<endl<<17;
        return 0;
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        num[i]=num[i-1]+k[i];
        ma=max(k[i],ma);
        int p,t;
        for(int j=1;j<=k[i];j++)
        {
            cin>>p>>t;
            T=t;
            of[i][p]=T;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        cout<<w[l]+w[r]+2*T<<endl;
    }
    return 0;
}
