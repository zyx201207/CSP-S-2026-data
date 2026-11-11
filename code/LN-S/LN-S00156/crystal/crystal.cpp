#include <bits/stdc++.h>
using namespace std;
int n,a[500005]={0},b[500005]={0},ans = 0,ans1 = 0,c = 1;
long long m,sum = 0,sum1 = 0;
void ab(int d)
{
    for(int i = d;i < n;i ++)
    {
        sum += b[i]*(i - d + 1);
        if(sum <= m)
        {
            sum1 = max(sum,sum1);
            ans ++;
            ans1 = max(ans,ans1);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    freopen("crystal.in" ,"r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m >> a[0];
    bool dc = 1;
    for(int i = 0;i < n;i ++)
    {
        cin >> a[i];

    }
    sort(a,a+n);
    for(int i = 0;i < n;i ++)
    {
        b[i - 1] = a[i] - a[i - 1];
    }
    for(int i = 1;i < n - 1;i ++)
    {
        if(b[i] != b[i - 1])
        {
            dc = 0;
        }
    }
    if(dc)
    {
        while(1)
        {
            sum += c*b[1];
            if(sum <= m){
            ans ++;
            c++;}
            else {
                break;
            }
        }
        cout << ans + 1;
        return 0;
    }
    for(int i = 0;i < n;i ++)
    {
        sum = 0;
        ans = 0;
        ab(i);
    }
    cout << ans1 + 1;
    return 0;
}
