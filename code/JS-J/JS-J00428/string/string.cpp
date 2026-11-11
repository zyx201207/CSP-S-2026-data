#include<bits/stdc++.h>
using namespace std;
struct tint
{
    long long myleft,myright;
    int v;
    tint(long long x,long long y,int z)
    {
        myleft=x;
        myright=y;
        v=z;
    }
};
set<long long> pv;
struct st
{
    int t;
    long long d;
    vector<tint> f;
    void beg()
    {
        t=0;
        d=0;
        f.clear();
    }
    void push(int a,int b)
    {
        f.push_back({d+1,d+a,b});
        d=d+a;
        t++;
    }
    int gn()
    {
        int l=0,r=t-1;
        long long u,cnt=0;
        for(u=1;u<=(d>>1);u++)
        {
            if(f[l].myright<u) l++;
            if(f[r].myleft>(d-u+1)) r--;
            if(f[l].v!=f[r].v) cnt++;
        }
        return cnt;
    }
    /*int gn(int q)
    {
        int l=0,r=t-1,mid,ans;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(f[mid].myleft<=q&&f[mid].myright>=q)
            {
                return f[mid].v;
            }
            if(f[mid].myleft>q) r=mid-1;
            else if(f[mid].myright<q) l=mid+1;
        }
        mid=r-1;
        for(l=1;l<=3;l++)
        {
            if(f[mid].myleft<=q&&f[mid].myright>=q)
            {
                return f[mid].v;
            }
        }
    }*/
    void pd()
    {
        int i;
        long long g=(d+1)>>1,tl,tr;
        pv.insert(g);
        for(i=0;i<t;i++)
        {
            tr=d-f[i].myleft+1;
            tl=d-f[i].myright+1;
            if(f[i].myright<=g) pv.insert(f[i].myleft),pv.insert(f[i].myright);
            else if(f[i].myleft>=g) pv.insert(tl),pv.insert(tr);
            else
            {
                pv.insert(f[i].myleft);
                pv.insert(tr);
            }
        }
    }
}p;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    pv.clear();
    p.beg();
    int n,a,b;
    long long i;
    char c;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>c;
        b=c-'a';
        if(a!=0) p.push(a,b);
    }
    bool hb;
    if(p.t<2) cout<<0;
    else
    {
        cout<<(p.gn());
    }
    return 0;
}
