#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],cho[100005],l,ans=1;
bool flag;
long long qp(long long a,long long b)
{

    long long res=1;
    while(b)
    {

        if(b&1) res=res*a;

        a=a*a;

        b>>=1;
    }
    return res;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    l=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);


    l=4;
    for(int i=1;i<m+1;i++)
    {

        ans=(a[i] & a[i+1]);

    }



    cout<<ans;
    return 0;
}
