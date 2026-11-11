#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int MAXN=5e5+5;
long long a[MAXN];
long long sum;
int ans=-1;
vector<long long> v;
void do_Special()
{
    long long d=a[2]-a[1];
    v.clear();
    long long cur=0;
    for(int i=1;i<=n;i++)
    {
        cur+=i;
        if(cur>m/d)
        {
            cout<<i;
            return;
        }
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    bool flags=true;
    for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flags=false;
    if(flags) do_Special();
    else
    {
        for(int i=1;i<=n;i++)
        {
            sum=0;
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]!=a[j-1])
                    sum+=(a[j]-a[j-1])*(j-i);
                if(sum>m)
                {
                    ans=max(ans,j-i);
                    break;
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
