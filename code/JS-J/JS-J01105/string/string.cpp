#include<bits/stdc++.h>
using namespace std;

struct Int
{
    int len;
    char c;
} ;

typedef long long ll;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    map<char,vector<pair<ll,ll> > > m;
    vector<Int> v;
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a; cin>>a;
        char s; cin>>s;
        m[s].push_back({sum,a});
        Int cc;
        cc.len=a; cc.c=s;
        v.push_back(cc);
        sum+=a;
    }
    if(n>2000&&sum>500)
    {
        ll i=0,j=n-1,sum1=0,sum2=0,ans=0;
        bool oki=true,okj=true;
        while(i<j)
        {
            ll k=sum1,l=sum2;
            if(oki) sum1+=v[i].len;
            if(okj) sum2+=v[j].len;
            if(v[i].c!=v[j].c)
            {
                if(k<l)
                    if(sum1<sum2)
                        ans+=ceil((v[i].len)*1.0/2);
                    else
                        ans+=ceil((sum1-k)*1.0/2);
                else
                    if(sum1<sum2)
                        ans+=ceil(v[j].len*1.0/2);
                    else
                        ans+=ceil((sum2-l)*1.0/2);
            }
            if(sum1<sum2)  i++,oki=true,okj=false;
            if(sum1>sum2)  j--,oki=false,okj=true;
            if(sum1==sum2) i++,j--,oki=true,okj=true;
        }
        cout<<ans<<endl;
    }
    else
    {
        ll i=0,j=sum-1;
        int ans=0;
        while(i<j)
        {
            char c=' ',d=' ';
            for(auto p:m)
            {
                if(c!=' '&&d!=' ') break;
                for(auto p1:p.second)
                {
                    if(p1.first<=i&&p1.first+p1.second-1>=i)
                        c=p.first;
                    if(p1.first<=j&&p1.first+p1.second-1>=j)
                        d=p.first;
                }
            }
            if(c!=d) ans++;
            i++,j--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
