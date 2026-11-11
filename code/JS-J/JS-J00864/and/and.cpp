#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N],ans;
void fun1()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(m==1)
    {
        cout<<a[n];
        return;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return;
    }
    ans=a[n]&a[n-1];
    cout<<ans;
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    fun1();
    return 0;
}
