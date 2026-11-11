#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int en[500005];
long long table[5005][5005];
int half(int l,int r)
{
    if(l==r)
    {
        return l;
    }
    int mid=(r-l+1)/2+l;
    long long low=m+1;
    for(int i=mid-1;i<=n-1;i++)
    {
        long long pre=0;
        for(int j=i-mid+1;j<i;j++)
        {
            pre+=en[i]-en[j];
        }
        low=min(low,pre);
    }
    
    if(low<=m)
    {
        return half(mid,r);
    }
    else{
        return half(l,mid-1);
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int flag=1;
    for(int i=0;i<n;i++)
    {
        cin>>en[i];
    }
    sort(en,en+n-1);
    for(int i=2;i<=n-1;i++)
    {
        if(en[i]-en[i-1]!=en[i-1]-en[i-2])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        int i=1;
        for(;i<=n;i++)
        {
            m-=en[n-1]-en[n-i];
            if(m<0)
            {
                break;
            }
        }
        cout<<i-1;
        return 0;
    }
/*    for(int i=n-1;i>=0;i--)
    {
        table[i][i]=0;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            table[i][j]=table[i][j+1]+en[i]-en[j];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=n-i;j>=0;j--)
        {
            if(table[j+i-1][j]<=m)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }*/
    cout<<half(1,n);
    return 0;
}