#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long g,from,to;
    char k;
};
node f[int(2e5)+5];
long long n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    f[1].from = 1;
    long long w = 0,ans = 0;
    for(int i = 1;i<=t;i++)
    {
        cin>>n;
        cin>>f[i].k;
        f[i].g = n;
        w+=n;
        f[i].to = f[i].from+n-1;
        f[i+1].from = f[i].to+1;
    }
    int l = 1;
    int r = t;
    long long z = w/2;
    for(long long i = 1;i<=z;)
    {
        if(f[l].to<i)
        {
            l++;
        }
        if(f[r].from>w-i+1)
        {
            r--;
        }
        if(f[l].k!=f[r].k)
        {
            if(f[l].g == f[r].g)
            {
                ans+=f[l].g;
                i+=f[l].g;
            }
            else if(f[l].g > f[r].g)
            {
                ans+=f[r].g;
                f[l].g-=f[r].g;
                i+=f[r].g;
            }
            else if(f[l].g < f[r].g)
            {
                ans+=f[l].g;
                f[r].g-=f[l].g;
                i+=f[l].g;
            }
        }
        else if(f[l].k==f[r].k)
        {
            if(f[l].g == f[r].g)
            {
                i+=f[l].g;
            }
            else if(f[l].g > f[r].g)
            {
                f[l].g-=f[r].g;
                i+=f[r].g;
            }
            else if(f[l].g < f[r].g)
            {
                f[r].g-=f[l].g;
                i+=f[l].g;
            }
        }
    }
    cout<<ans;
    return 0;
}
