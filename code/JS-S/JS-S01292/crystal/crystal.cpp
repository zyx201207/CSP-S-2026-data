#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans;
void f(int d,long long mm,int gs)
{
    if(d>n)
    {
        ans=max(ans,gs);
        return ;
    }
    if(mm>=gs*(a[d+1]-a[d]))
    {
        f(d+1,mm-gs*(a[d+1]-a[d]),gs+1);
        f(d+1,mm,gs);
    }
    else
    {
        ans=max(ans,gs);
        return ;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=16)
    {
        f(1,m,1);
        cout<<ans<<endl;
        return 0;
    }
    int cha=a[2]-a[1],o=1;
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=cha)
        {
            o=0;
            break;
        }
    }
    if(o==1)
    {
        int x=1;
        long long mm=m;
        while(1)
        {
            if(x*cha<=mm)
            {
                mm-=x*cha;
                x++;
            }
            else break;
        }
        cout<<x<<endl;
        return 0;
    }
    else cout<<"1"<<endl;
    return 0;
}
//>=55pts
