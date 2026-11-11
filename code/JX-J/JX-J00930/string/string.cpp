#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,cnt=0,maxn=0,c,minn=999;
    long long sum=0;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        maxn=max(maxn,a);
        minn=min(a,minn);
        sum+=a;
    }
    if(n==2)
    {

        cout<<minn;
        return 0;
    }

    if(maxn==1)
    {
        cout<<sum/2;
        return 0;
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }

    return 0;
}
