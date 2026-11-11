#include<bits/stdc++.h>
using namespace std;
int x[1005],y[1005];
int w[1005];
long long a[10005];
int q=0;
int s=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int j=1;
    while(a[n]!=0)
    {
        x[j]=a[n]%2;
        a[n]=a[n]/2;
        j++;
    }
    int l=1;
    while(a[n-1]!=0)
    {
        y[l]=a[n-1]%2;
        a[n-1]=a[n-1]/2;
    }
    int c;
    if(j>l)
    {
        c=j;
    }
    else{
        c=l;
    }
    for(int i=1;i<=c;i++)
    {
        if(x[i]==1&&y[i]==1)
        {
            w[i]=1;
        }
        else{
            w[i]=0;
        }
    }
    int k=0;
    for(int i=1;i<=c;i++)
    {
        s+=w[i]*k;
        if(i==1)
        {
            k+=2;
        }
        else{
            k*=2;
        }
    }
    cout<<s;
}
