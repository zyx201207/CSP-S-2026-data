#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans,ha;
bool cmp(int a,int b)
{
    return a>b;
}
void fun(int r,long long x)
{
    sort(a+1,a+1+r,cmp);
    int p=0;
    while(p<m)
    {
        p=0;
        //cout<<x<<" ";
        for(int i=1;i<=r;i++)
        {
            if(a[i]>=x)
            {
                //cout<<a[i]<<" ";
                p++;
            }
        }
        if(x==1)
        {
            if(p>=m) ans++;
            return;
        }
        x/=2;
        //cout<<endl;
    }
    //cout<<x*2<<endl;
    ans+=x*2;
    for(int i=1;i<=p;i++)
    {
        a[i]=a[i]%(x*2);
    }
    fun(p,x);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ha=pow(2,31);
    fun(n,ha);
    cout<<ans;
    return 0;
}
