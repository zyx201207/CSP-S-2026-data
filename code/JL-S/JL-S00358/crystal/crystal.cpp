#include<bits/stdc++.h>
using namespace std;
long a[50005],cha[50005];
int n,m,ans=1;
int mcha,p,t,v;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    mcha=a[n];
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            ans++;t=1;
        }

        else t=0;
    }
    if(t==1 )ans=n;

    for(int i=1;i<=n-1;i++){
        if(cha[i]==cha[i+1])
             v=1;
         else v=0;
    }
    if(v==1){
        ans=ans+(m/cha[1]);
    }

    for(int i=2;i<=n;i++)
    {
        cha[i]=a[i]-a[i-1];
        if(cha[i]<mcha){
            mcha=cha[i];
            p=i;
        }
        else if(cha[i]==mcha){
            if(i<p)p=i;
        }
    }
    if(mcha>m)ans=0;
    else if(mcha==m)ans=2;

    m=m-mcha;
    a[p-1]=a[p];


/*
    while(m>0)
    {
        if(a[p]-a[p-1]<=m){
            m=m-(a[p]-a[p-1]);
            ans++;
            a[p-1]=a[p];

        }
    }*/
    cout<<ans<<endl;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
}
