#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
struct node
{
    ll sum;
    char c;
}a[maxn];
int n;
queue<node> q;
ll len,ans,l,r;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].sum);
        cin >> a[i].c;
        len += a[i].sum;
    }
    ll mid = len / 2;
    int pos = 0;
    for(int i=1;i<=n;i++)
    {
        if(l + a[i].sum <= mid) l += a[i].sum,q.push({a[i].sum,a[i].c});
        else
        {
            if(mid != l) q.push({mid - l,a[i].c});
            pos = i;
            break;
        }
    }
    for(int i=pos;i<=n && q.size();)
    {
        
        node t = q.front();
        q.pop();
        if(t.sum < a[i].sum)
        {
            if(t.c == a[i].c)
            {
                a[i].sum -= t.sum;
            }
            else {ans += t.sum;}
            q.pop();
            
        }
        if(t.sum == a[i].sum)
        {
            
            if(t.c != a[i].c) ans += t.sum;
            i ++;
            q.pop();
            
        }
        else
        {
            if(t.c == a[i].c)
            {
                q.push({t.sum - a[i].sum,t.c});
            }
            else {ans += a[i].sum;}
            i ++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}