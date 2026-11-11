#include<bits/stdc++.h>
using namespace std;
int a[50050],b[50050],k,sum=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[n])
            {
                continue;
            }
            if(a[i]>a[i+1])
            {
               k=a[i];
               a[i]=a[i+1];
               a[i+1]=k;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i+1]-a[i];
        if(a[i]==a[n])
        {
                continue;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]+b[i+1]==m)
        {
            cout<<a[i+1]<<endl;
        }
    }
}
