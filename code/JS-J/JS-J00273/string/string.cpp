#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,L=0,ans=0;
string s;
struct zichuan
{
    int left,right,a,num;
    char c;
};
zichuan zc[200001];

int findmid(int mid)
{
    int x;
    for(int i=1;i<=n;i++)
    {
        if(mid>=zc[i].left && mid<=zc[i].right)
        {
            x=i;
            break;
        }
    }
    return x;
}

void add(int l,int r,int midx)
{
    int zuosh=0,yoush=0;
    while(l<=midx && r>=midx)
    {
        if(l==midx && r==midx)
        {
            break;
        }
        if(zc[l].a>zc[r].a)
        {
            if(zc[l].c!=zc[r].c)
            {
                ans+=zc[r].a;
            }
            zuosh=zc[l].a-zc[r].a;
            zc[l].a=zuosh;
            r--;
        }
        else if(zc[l].a==zc[r].a)
        {
            if(zc[l].c!=zc[r].c)
            {
                ans+=zc[r].a;
            }
            l++;
            r--;
        }
        else
        {
            if(zc[l].c!=zc[r].c)
            {
                ans+=zc[l].a;
            }
            yoush=zc[r].a-zc[l].a;
            zc[r].a=yoush;
            l++;
        }
    }
    return;
}

void addtwo(int l,int r,int midxl,int midxr)
{
    int zuosh=0,yoush=0;
    while(l<=midxl && r>=midxr)
    {
        if(zc[l].a>zc[r].a)
        {
            if(zc[l].c!=zc[r].c)
            {
                ans+=zc[r].a;
            }
            zuosh=zc[l].a-zc[r].a;
            zc[l].a=zuosh;
            r--;
        }
        else if(zc[l].a==zc[r].a)
        {
            if(zc[l].c!=zc[r].c)
            {
                ans+=zc[r].a;
            }
            l++;
            r--;
        }
        else
        {
            if(zc[l].c!=zc[r].c)
            {
                ans+=zc[l].a;
            }
            yoush=zc[r].a-zc[l].a;
            zc[r].a=yoush;
            l++;
        }
    }
    return;
}

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int sum=1;
    for(int i=1;i<=n;i++)
    {
        cin>>zc[i].a>>zc[i].c;
        L+=zc[i].a;
        zc[i].left=sum;
        sum+=(zc[i].a-1);
        zc[i].right=sum;
        sum++;
        zc[i].num=i;
    }
    if(L%2==1)
    {
        int mid=L/2+1;
        int midx=findmid(mid);
        int l=1,r=n;
        add(l,n,midx);
    }
    else
    {
        int midl=L/2;
        int midr=L/2+1;
        int midxl=findmid(midl);
        int midxr=findmid(midr);
        int l=1,r=n;
        addtwo(l,n,midxl,midxr);
    }
    cout<<ans;
    return 0;
}
