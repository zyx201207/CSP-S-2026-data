#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node
{
    long long a;
    char c;
}p[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long l=1,r=n;
    for(int i=1;i<=n;i++)   cin>>p[i].a>>p[i].c;
    while(l<=r)
    {
        if(p[l].a>=p[r].a&&p[l].c==p[r].c)
        {
            p[l].a-=p[r].a;
            r--;
        }
        if(p[l].a>=p[r].a&&p[l].c!=p[r].c)
        {
            ans+=p[r].a;
            p[l].a-=p[r].a;
            r--;
        }
        if(p[l].a<=p[r].a&&p[l].c==p[r].c)
        {
            p[r].a-=p[l].a;
            l++;
        }
        if(p[l].a<=p[r].a&&p[l].c!=p[r].c)
        {
            ans+=p[l].a;
            p[r].a-=p[l].a;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
