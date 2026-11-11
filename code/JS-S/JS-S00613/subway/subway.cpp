#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500010];
vector<ll> a[510];
vector<ll> t[510];
ll k[510];
map<ll,ll> z2s[500010];
ll fd[510][510];
void if2()
{
    for(ll k=1; k<=n; k++)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                fd[i][j] = min(fd[i][j],fd[i][k]+fd[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(ll i=1; i<=m; i++)cin>>w[i];
    for(ll i=1; i<=n; i++)
    {
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(ll j=1; j<=k[i]; j++)
        {
            ll t1,t2;
            cin>>t1>>t2;
            a[i].push_back(t1);
            t[i].push_back(t2);
        }
    }

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1;j<=n;j++){
            if(i==j)
                fd[i][i] = 0;
            else
                fd[i][j] = 2305843009213693952ll;
        }
    }

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=k[i]; j++)
        {
            ll t1 = a[i][j];
            z2s[t1][i] = t[i][j];
        }
    }
    // z2s[i][j] station[i] to subway[j] 's minute


    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=k[i]; j++)
        {
            ll t1 = a[i][j];
            for(auto pr:z2s[t1])
            {
                if(i == pr.first) continue;
                //cout<<"sw:"<<i<<" zhan:"<<t1<<" 2sw:"<<pr.first<<" time:"<<pr.second<<" metime:"<<t[i][j]<<endl;
                fd[i][pr.first] = min(fd[i][pr.first],pr.second + t[i][j]);

            }
        }
    }
    if (0)
    {
        for(ll i=1; i<=n; i++)
            for(ll j=1; j<=n; j++)
            {
                //cout<<i<<" "<<j<<" "<<mp[i][j]<<endl;
                fd[i][j] = fd[i][j];
            }
    }
    if2();
    /*
        for(ll i=1; i<=m; i++)
        {
            for(auto pr:z2s[i])
            {
                //if(i == pr.first) continue;
                cout<<"zhan:"<<i<<" 2sw:"<<pr.first<<" time:"<<pr.second<<endl;

            }
        }
    */

    for(ll r=1; r<=q; r++)
    {
        ll xr,yr;
        cin>>xr>>yr;
        ll s1,s2;
        ll mi = 2305843009213693952ll;
        for(auto t1:z2s[xr])
        {
            ll tosw = t1.first;
            ll time1 = t1.second+w[xr];
            for(auto t2:z2s[yr])
            {
                ll edsw = t2.first;
                ll time2 = t2.second+w[yr];
                //fd[tosw][edsw]; minest path mllues
                ll atime = time1+time2+fd[tosw][edsw];
                mi = min(mi,atime);

            }
        }
        cout<<mi<<endl;
    }
    return 0;
}

