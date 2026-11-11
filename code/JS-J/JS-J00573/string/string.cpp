#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str
{
    char c;
    int x;
};
int n,mid=0,lenx=0,t=0;
str a[200010];
stack<str> l,r;
int minf(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
        lenx+=a[i].x;
    }
    mid=lenx/2;
    lenx=0;
    while(lenx<mid)
    {
        t++;
        l.push(a[t]);
        lenx+=a[t].x;
    }
    l.top().x-=lenx-mid;
    lenx=0;
    t=n+1;
    while(lenx<mid)
    {
        t--;
        r.push(a[t]);
        lenx+=a[t].x;
    }
    r.top().x-=lenx-mid;
    int ans=0;
    //cout<<r.top().c<<" "<<r.top().x<<" "<<l.top().x<<" "<<l.top().c<<endl;
    while(!l.empty()&&!r.empty())
    {
        if(l.top().c==r.top().c)
        {
            int q=min(l.top().x,r.top().x);
            l.top().x-=q;
            r.top().x-=q;
            if(l.top().x==0)
                l.pop();
            if(r.top().x==0)
                r.pop();
        }
        else
        {
            int q=min(l.top().x,r.top().x);
            l.top().x-=q;
            r.top().x-=q;
            if(l.top().x==0)
                l.pop();
            if(r.top().x==0)
                r.pop();
            ans+=q;
            //cout<<"1 ";
        }
    }
    cout<<ans;
    return 0;
}
