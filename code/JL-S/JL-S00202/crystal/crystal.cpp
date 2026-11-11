#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n1;
long long baosou(int i,int n,int m)
{
    if(i==n)
    {
        return 1;
    }
    unsigned long long int sum=0;
    for(int j=i;j<=n;j++)
    {
        sum=sum+a[n]-a[j];
    }
    if(sum<=m)
    {
        return n-i+1;
    }
    else{
        if(a[n]-a[n-1]>a[i+1]-a[i])
        {
            return baosou(i,n-1,m);
        }
        else
        {
            return baosou(i,n+1,m);
        }
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    n1=n;
    bool A=1,B=1;
    long long cha=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=i)
        {
            A=0;
        }
        if(n>2&&i==2)
        {
            cha=a[2]-a[1];
        }
        if(n>2&&i>2)
        {
            if(a[i]-a[i-1]!=cha)
            {
                B=0;
            }
        }
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n==2)
    {
        if(abs(a[1]-a[2])<=m){
            cout<<2;
            return 0;
        }
        else
        {
            cout<<1;
            return 0;
        }
    }
    if(A==1)
    {
        long long cnt=1;
        for(int i=1;i<=n;i++)
        {
            m-=i;
            if(m>=0)
            {
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    if(B==1)
    {
        long long cnt=1;
        for(int i=1;i<=n;i++)
        {
            m-=i*cha;
            if(m>=0)
            {
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    if(n==3)
    {
        if(a[3]-a[1]+a[3]-a[2]<=m)
        {
            cout<<3;
            return 0;
        }
        else if(a[2]-a[1]<=m)
        {
            cout<<2;
            return 0;
        }
        else if(a[3]-a[2]<=m)
        {
            cout<<2;
            return 0;
        }
        cout<<1;
        return 0;
    }
    if(n==4)
    {
        if((3*a[4]-a[1]-a[2]-a[3])<=m)
        {
            cout<<4;
        }
        else if(a[3]-a[1]+a[3]-a[2]<=m)
        {
            cout<<3;
            return 0;
        }
        else if(a[2]-a[1]<=m)
        {
            cout<<2;
            return 0;
        }
        else if(a[3]-a[2]<=m)
        {
            cout<<2;
            return 0;
        }
        else if(a[4]-a[2]+a[4]-a[3]<=m)
        {
            cout<<3;
            return 0;
        }
        else if(a[4]-a[3]<=m)
        {
            cout<<2;
            return 0;
        }
        else
        {
            cout<<1;
            return 0;
        }
    }
    if(n==5)
    {
        if(4*a[5]-a[1]-a[2]-a[3]-a[4]<=m)
        {
            cout<<5;
            return 0;//5,4,3,2,1
        }
        else if((3*a[4]-a[1]-a[2]-a[3])<=m)
        {
            cout<<4;//4321
        }
        else if(a[3]-a[1]+a[3]-a[2]<=m)
        {
            cout<<3;
            return 0;//321
        }
        else if(a[2]-a[1]<=m)
        {
            cout<<2;
            return 0;//21
        }
        else if(a[3]-a[2]<=m)
        {
            cout<<2;
            return 0;//32
        }
        else if(a[4]-a[2]+a[4]-a[3]<=m)
        {
            cout<<3;
            return 0;//432
        }
        else if(a[4]-a[3]<=m)
        {
            cout<<2;//43
            return 0;
        }
        else if((3*a[5]-a[4]-a[3]-a[2])<=m)
        {
            cout<<4;//5432
        }
        else if(a[5]-a[4]+a[5]-a[3]<=m)
        {
            cout<<3;//543
            return 0;
        }
        else if(a[5]-a[4]<=m)
        {
            cout<<2;//54
            return 0;
        }
        else if(a[4]-a[3]<=m)
        {
            cout<<2;//43
            return 0;
        }
        else
        {
            cout<<1;
            return 0;
        }
    }
    if(n>=5)
    {
        cout<<baosou(1,n,m);
    }
    return 0;
}
