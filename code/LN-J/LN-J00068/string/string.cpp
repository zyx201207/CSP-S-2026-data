#include <bits/stdc++.h>
using namespace std;
struct block
{
    long long l,r;
    char c;
};
vector<block> v1,v;
int n,j,m;
long long mid,last,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long len;
        char c;
        cin>>len>>c;
        v1.push_back({last+1,last+len,c});
        last+=len;
    }
    mid=(last+1)/2;
    if(last%2)
    {
        for(int i=0;i<v1.size();i++)
        {
            auto x=v1[i];
            long long l=x.l,r=x.r;
            char c=x.c;
            long long len=r-l+1;
            if(mid>len||mid<=0)
            {
                mid-=len;
                v.push_back({l,r,c});
            }
            else if(mid==len)
            {
                int len1=mid;
                mid-=len;
                if(len==1)
                {
                    m=v.size()-1;
                    continue;
                }
                v.push_back({l,l+len1-2,c});
                m=v.size()-1;
            }
            else if(mid==1)
            {
                int len1=mid;
                m=v.size()-1;
                mid-=len;
                if(len==1)
                {
                    continue;
                }
                v.push_back({l+1,r,c});
            }
            else
            {
                v.push_back({l,l+mid-2,c});
                m=v.size()-1;
                v.push_back({l+mid,r,c});
                mid-=len;
            }
        }
    }
    else
    {
        for(int i=0;i<v1.size();i++)
        {
            auto x=v1[i];
            long long l=x.l,r=x.r;
            char c=x.c;
            long long len=r-l+1;
            if(mid>len||mid<0)
            {
                mid-=len;
                v.push_back({l,r,c});
            }
            else if(mid==len)
            {
                v.push_back({l,l+mid-1,c});
                m=v.size()-1;
                mid=-1;
            }
            else if(mid==1)
            {
                v.push_back({l,l,c});
                m=v.size()-1;
                v.push_back({l+1,r,c});
                mid=-1;
            }
            else
            {
                v.push_back({l,l+mid-1,c});
                m=v.size()-1;
                v.push_back({l+mid,r,c});
                mid=-1;
            }
        }
    }
    j=v.size()-1;
    for(int i=0;i<=m;i++)
    {
        auto x=v[i],y=v[j];
        long long l1=x.l,r1=x.r,l2=y.l,r2=y.r;
        long long len1=r1-l1+1,len2=r2-l2+1;
        char c1=x.c,c2=y.c;
        while(len1>0)
        {
            if(len1>=len2)
            {
                len1-=len2;
                if(c1!=c2)
                {
                    ans+=len2;
                }
                j--;
                v.pop_back();
            }
            else
            {
                if(c1!=c2)
                {
                    ans+=len1;
                }
                v.pop_back();
                v.push_back({l2,r2-len1,c2});
            }
            y=v[j];
            l2=y.l,r2=y.r;
            len2=r2-l2+1;
            c2=y.c;
        }
    }
    cout<<ans;
}
