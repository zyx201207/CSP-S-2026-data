#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,re=0;
    int a[100005],b[100005];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[i])
            {
                re=a[j];
                a[j]=a[i];
                a[i]=re;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    int k1=0,k2=n-1;
    int lj1=0,lj2=0,ans1=0,ans2=0;
    while(lj1<m)
    {
        if(k1<n-1 && lj1+b[k1]<=m)
        {
            lj1+=b[k1];
            k1+=1;
            ans1+=1;
        }
        else
            break;
    }
    while(lj2<m)
    {
        if(k2>=0 && lj2+b[k2]<=m)
        {
            lj2+=b[k2];
            k2-=1;
            ans2+=1;
        }
        else
            break;
    }
    if(ans1>ans2)
        cout<<ans1<<endl;
    else
        cout<<ans2<<endl;
    return 0;
}
