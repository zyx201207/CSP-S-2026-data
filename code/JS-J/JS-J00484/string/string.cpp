#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005];
    char c[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long sum=0;
    int l=1,r=n;
    long long nowl=a[l],nowr=a[r];
    while(l<=r)
    {
        if(nowl<nowr)
        {
            if(c[l]!=c[r])sum+=nowl;
            nowr=nowr-nowl;
            nowl=a[++l];
            continue;
        }
        else
        {
            if(c[l]!=c[r])sum+=nowr;
            nowl=nowl-nowr;
            nowr=a[--r];
            continue;
        }
    }
    cout<<sum;
}
