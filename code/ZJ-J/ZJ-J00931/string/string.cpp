#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
    int cnt,vis=0;
    char s;
} a[200005];
ll sum = 0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i].cnt >> a[i].s;
        sum += (ll)a[i].cnt;
    }
    ll sumx = 0,lastx=n;
    ll ans = 0;
    for (ll i = 1; i <= n;i++)
    {
        ll tmp = a[i].cnt,tmpx=lastx;
        if(sumx>=sum/2)
            break;
        else if(sumx+tmp>sum/2)
        {
            tmp = sum / 2 - sumx;
            sumx = sum / 2;
        }
        else sumx += tmp;
        for (int j = lastx; j >= 1;j--)
        {
            if(tmp>0)
            {
                if(a[j].s==a[i].s)
                {
                    if(tmp<=a[j].cnt-a[j].vis)
                    {
                        a[j].vis += tmp;
                        tmp = 0;
                    }
                    else{
                        tmp -= (a[j].cnt-a[j].vis);
                        a[j].vis = a[j].cnt;
                        lastx--;
                    }
                }
                else
                {
                    if(tmp<=a[j].cnt-a[j].vis)
                    {
                        ans+=tmp;
                        a[j].vis = a[j].vis + tmp;
                        tmp = 0;
                    }
                    else
                    {
                        tmp -= a[j].cnt-a[j].vis;
                        ans += a[j].cnt-a[j].vis;
                        a[j].vis = a[j].cnt;
                        lastx--;
                    }
                }
                // cout << lastx << ' ' << tmp << ' ' << a[lastx].vis << ' ' << ans << '\n';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}