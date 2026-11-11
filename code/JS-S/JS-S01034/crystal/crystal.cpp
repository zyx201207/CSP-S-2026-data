#include <bits/stdc++.h>
using namespace std;
int a[500002];
bool cmp(int a1,int b1)
{
    return a1<b1;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    int cnt=1;
    while(m>0)
    {
        if(a[cnt]==a[cnt+1])
        {
            cnt++;
            continue;
        }
        if(m>=cnt)
        {
            m-=cnt;
            continue;
        }
        cout << cnt;
    }
    return 0;
}
