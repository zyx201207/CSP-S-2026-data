#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[2000010];
pair<ll,ll> f[2000010];
bool check(ll l,ll r,ll d)
{
    //cout<<r<<endl;
    for(ll i=0; i<=r; i++)
    {
        f[i].first = 2305843009213693952ll;
    }
    // f[i] 落脚点在i处的最小值和方法数
    f[l] = {0,1};

    ll l1 = l;
    for(ll i =l+1; i<=r; i++)
    {
        bool flag = false;
        for(ll j = l1; j<i; j++)
        {
            if(x[i]-x[j]>d)continue;
            if(!flag)
            {
                l1 = j;
                flag = true;
            }
            /*
            if(l==1 && r==5)
                cout<<"^ i:"<<i<<" j:"<<j<<" f[i]:"<<f[i].first<<" "<<f[i].second<<" f[j]:"<<f[j].first<<" "<<f[j].second<<endl;
            */if(f[i].first < f[j].first+1) continue;
            if(f[i].first == f[j].first+1)
            {
                f[i].second++;
                continue;
            }
            f[i] = make_pair(f[j].first+1,f[j].second);
        }/*
        if(l==1 && r==5)
            cout<<"* i:"<<i<<" f[i]:"<<f[i].first<<" "<<f[i].second<<endl;
            */
    }

    if(0)
    {
        cout<<"l:"<<l<<" r:"<<r<<endl;
        for(ll i=l; i<=r; i++)
        {
            cout<<i<<":"<<f[i].first<<" "<<f[i].second<<endl;
        }
        cout<<endl;
    }
    if(f[r].second == 2)
    {
        if(0) cout<<"%%"<<l<<" "<<r<<endl;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);





    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ll c,T;
    cin>>c>>T;
    while(T--)
    {
        ll n,d;
        ll cnt = 0;
        memset(x,0,sizeof(x));
        cin>>n>>d;
        for(ll i=1; i<=n; i++) cin>>x[i];
        for(ll r=1; r<=n; r++)
        {
            for(ll l=1; l<=r; l++)
            {
                if(check(l,r,d))
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
