#include<bits/stdc++.h>
using namespace std;
struct ch
{
    long long s;
    char c;
};
vector<ch> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,len=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        int x;char c;
        cin>>x>>c;
        v.push_back({x,c});
    }
    cout<<n<<"\n";
    long long r=n-1,l=0,ans=0;
    char c;
    while(l<r)
    {
        if(v[l].c==v[r].c)
        {
            if(v[l].s>v[r].s)
            {
                v[l].s=v[l].s-v[r].s;
                r--;
            }
            else if(v[l].s<v[r].s)
            {
                v[r].s=v[r].s-v[l].s;
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        else
        {
            if(v[l].s>v[r].s)
            {
                v[l].s=v[l].s-v[r].s;
                ans+=v[r].s;
                r--;
            }
            else if(v[l].s<v[r].s)
            {
                v[r].s=v[r].s-v[l].s;
                ans+=v[l].s;
                l++;
            }
            else
            {
                ans+=v[l].s;
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
