#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum=0;
ll num=0;
struct node{
    ll L,R;
    char ch;
}a[200003];
int n;
vector<node> ls,rs;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll tmp;
        cin>>tmp>>a[i].ch;
        a[i].L=sum+1;
        sum+=tmp;
        a[i].R=sum;
    }
    ll sumt=sum;
    bool f=sum%2;
    sum/=2;
    sum+=f;
    for(int i=1;i<=n;i++)
    {
        if(a[i].L<=sum&&a[i].R>=sum)
        {
            if(f)
            {
                for(int j=1;j<i;j++)
                    ls.push_back(a[j]);
                if(sum!=a[i].L)ls.push_back({a[i].L,sum,a[i].ch});
                for(int j=n;j>i;j--)
                    rs.push_back({a[j].L,a[j].R,a[j].ch});
                if(sum!=a[i].R)rs.push_back({sum+1,a[i].R,a[i].ch});

            }
            else
            {
                for(int j=1;j<i;j++)
                    ls.push_back(a[j]);
                if(sum!=a[i].L)ls.push_back({a[i].L,sum,a[i].ch});
                for(int j=n;j>i;j--)
                    rs.push_back({a[j].L,a[j].R,a[j].ch});
                if(sum!=a[i].R)rs.push_back({sum+1,a[i].R,a[i].ch});
            }
            break;
        }
    }
    ll rll=rs[rs.size()-1].L-1;
    for(int i=0;i<rs.size();i++)
    {
        rs[i].L-=rll;
        rs[i].R-=rll;
    }
    ll ri=0;
    for(node tmp:ls)
    {
        while(rs[ri].R<=tmp.R)
        {
            if(rs[ri].ch!=tmp.ch)num+=rs[ri].R-rs[ri].L+1;
            if(ri<rs.size()-1)ri++;
            else break;
        }
        if(ri==rs.size()-1)break;
        if(rs[ri].ch!=tmp.ch&&rs[ri].R>=tmp.R)
        {
            num+=tmp.R-rs[ri].L+1;
        }
        rs[ri].L=tmp.R;
    }
    cout<<num;
    return 0;
}
