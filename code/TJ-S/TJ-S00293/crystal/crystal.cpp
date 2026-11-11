#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,mx;
//long long cha[500005]={0},h[500005]={0},mx;//h:cha de qian zhui he
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,mid=(r-l+1)/2+l;
    bool b=0;
    while(l<n&&r>0&&l<=r)
    {
        for(int i=1;i<=n-mid;i++)
        {
            sum=0;
            for(int j=i;j<i+mid;j++)
            {
                sum+=a[i+mid]-a[j];
            }
            if(sum<=m)
            {
                b=1;
                mx=mid+1;
                break;
            }
        }
        if(b==1)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(r-l+1)/2+l;
    }
    cout<<mx;
    /*for(int i=1;i<n;i++)
    {
        cha[i]=a[i+1]-a[i];
        h[i]=h[i-1]+cha[i];
    }
    int l=1,r=n-1,mid=(r-l+1)/2+l;
    bool b=0;
    while(l<n&&r>0&&l<=r)
    {
        for(int j=1;j<=n-mid;j++)
        {
            if(h[j+mid-1]-h[j-1]<=m)
            {
                b=1;
                mx=mid;
                break;
            }
        }//kunsile,gsdccf
        if(b==1)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(r-l+1)/2+l;
        b=0;
    }
    cout<<mx+1;*/
    return 0;
}
