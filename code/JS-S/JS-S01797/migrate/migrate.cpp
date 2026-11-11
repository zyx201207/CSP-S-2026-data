#include<bits/stdc++.h>
using namespace std;
long long x[2000001];
void solve()
{
    long long n, d;
    cin >> n >> d;
    bool flag = 0;
    //cout << n << " " << d << '\n';
    for(int i = 1;i <= n;i ++)
    {
        cin >> x[i];
        if(i > 2 && x[i] - x[i - 1] != x[i - 1] - x[i - 2])
        {
            flag = 1;
        }
    }
   // for(int i = 1;i <= n;i ++)
    //{
    //    cout << x[i] << " ";
   // }
   // cout << '\n';

   if(flag == 0)
   {
       bool f = 1;
    int sum = 0;
    for(int i = 2;i < n - 1;i ++)
    {
       // cout << x[i + 1] - x[i - 1] << " " << x[i + 2] - x[i + 1] << " " << x[i] - x[i - 1] << " " << x[i + 2] - x[i] << " " << x[i + 2] - x[i - 1] << "\n";
        if(x[i + 1] - x[i - 1] <= d && x[i + 2] - x[i] <= d && x[i + 2] - x[i - 1] > d)
        {
            int lcnt = 1, rcnt = 1;
            int temp = i - 1;
            while(temp > 1 && x[temp + 1] - x[temp - 1] > d && x[temp] - x[temp - 1] <= d && (temp == 2 || x[temp] - x[temp - 2] > d))
            {
                temp --;
                lcnt ++;
            }
            temp = i + 2;
            while(temp < n && x[temp + 1] - x[temp - 1] > d && x[temp + 1] - x[temp] <= d && (temp == n - 1 || x[temp + 2] - x[temp] > d))
            {
                temp --;
                rcnt ++;
            }
            //cout << i << ":" << lcnt << " " << rcnt << '\n';
            sum += lcnt * rcnt;
        }
    }
    cout << sum << "\n";
   }
   else
   {
       int dif = x[2] - x[1];
       if(dif > d)
       {
           cout << "0\n";
       }
       else if((d + 1) / 2 < dif)
       {
            int i = 2;
            while((d + i - 1) / i > dif)
            {
                i ++;
            }
            i --;
            cout << n - i;
       }

   }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}

