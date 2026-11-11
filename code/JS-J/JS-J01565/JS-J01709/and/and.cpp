#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
bool aaa[200010];

int s(int t,bool pos[],int p)
{
    if(t == 0) return p;
    int Max = -1;
    for(int i = 0;i < n;i++)
    {
        if(pos[i]) continue;
        pos[i] = true;
        int x = p & a[i];
        Max = max(s(t - 1,pos,x),Max);
        pos[i] = false;
    }
    return Max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int bbb = 1;
    for(int i = 0;i < 21;i++)
    {
        bbb *= 2;
    }
    for(int i = 0;i < 200010;i++)
    {
        aaa[i] = false;
    }
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        int Max  = -1;
        for(int i = 0;i < n;i++)
        {
            Max = max(Max,a[i]);
        }
        cout << Max;
        return 0;
    }
    if(m == n)
    {
        int ans = a[0];
        for(int i = 1;i < n;i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 2)
    {
        int Max = -1;
        for(int i = 0;i < n - 1;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                Max = max(Max,a[i] & a[j]);
            }
        }
        cout << Max;
        return 0;
    }
    if(m == n - 1)
    {
        int Max = -1;
        int t = a[1];
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(j == i) continue;
                t &= a[j];
            }
            Max = max(Max,t);
            t = a[0];
        }
        cout << Max;
        return 0;
    }
    cout << s(m,aaa,bbb - 1);
    return 0;
}
