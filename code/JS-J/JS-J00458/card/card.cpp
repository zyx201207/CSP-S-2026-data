#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[300005]={},b[300005]={},pre[300005]={};
ll x;
struct card
{
    ll s;
    ll num=0;
    ll ls;
};
struct ans
{
    ll all;
    ll siz;
};
bool cmpa(card a,card b)
{
    return a.ls < b.ls;
}
bool cmpb(ans a,ans b)
{
    return a.siz < b.siz;
}
card cards[300005]={};
ans anss[300005]={};
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> x;
        cards[x].s=x;
        cards[x].num++;
        cards[x].ls = i;
    }
    sort(cards+1,cards+m+1,cmpa);
    for (int i=1; i<=n; i++)
    {
        a[i] = cards[i].num;
        pre[i] = pre[i-1]+a[i];
        anss[i].siz = cards[i].s;
        anss[i].all = pre[i];
    }
    sort(anss+1,anss+m+1,cmpb);
    for (int i=1; i<=m; i++)
    {
        cout << anss[i].all << ' ';
    }

    return 0;
}
