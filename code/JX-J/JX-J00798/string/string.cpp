#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a[200005];
    long long j[200005],ans=0;
    int n,l=1,L=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>j[i];
        cin>>a[i];
        if(a[i]==a[i-1])l++;
        if(j[i]==j[i-1])L++;
    }
    if(l==n)
    {
        cout<<0;
        return 0;
    }
    if(L==n)
    {
        long long x=0;
        for(int i=1;i<=n/2;i++)
        {
            if(a[i]==a[n-i+1])x++;
        }
        x=n/2-x;
        cout<<x*j[1];
    }else
{
    long long sum=0,x=1,y=0;
    char b[1000000];
    for(long long i=1;i<=n;i++)
    {
        sum+=j[i];
    }
    for(long long i=1;i<=n;i++)
    {
        y=x+j[i];
        x=y-j[i];
        for(long long k=1;k<=j[i];k++)
        {
            b[k]=a[i];
        }
    }
    for(long long i=1;i<=sum/2;i++){
        if(b[i]!=b[sum-i+1])ans++;
    }
    cout<<ans;}
    return 0;
}
