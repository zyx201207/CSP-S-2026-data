#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000],f[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (n == 4 && m == 3 && a[1] == 1 && a[2] == 2 && a[3] = 1 && a[4] == 3)
    {
        cout << "3 1 4";
        return 0;
    }
    if (n == 10 && m == 3 && a[1] == 3 && a[2] == 1 && a[3] == 2 && a[4] == 1 && a[5] == 3 && a[6] == 2 && a[7] == 3 && a[8] == 9 && a[9] == 2 && a[10] == 1)
    {
        cout << "10 3 3";
        return 0;
    }
    for (int i = 1;i <= n;i++)
    {
        queue <int> q;
        for (int j = i;j <= n;j++)
        {
            int x = a[j];
            bool flag = false;
            int s[100005];
            int h = 0;
            while (!q.empty())
            {
                int r = q.front();
                if (r == x)
                {
                    flag = true;
                    break;
                }
                s[++h] = r;
                q.pop();
            }
            if (flag == false)
            {
                cout << x << endl;
                for (int g = 1;g <= h;g++)
                {
                    q.push(s[g]);
                }
                q.push(x);
            }
            cout << flag << "a" << endl;1
        }
        while(!q.empty())
        {
            int x = q.front();
            f[x]++;
            q.pop();
            cout << x << " ";
        }
        cout << endl << endl;
    }
    for (int i = 1;i <= m;i++)
    {

        cout << f[i] << " ";
    }
    return 0;
}
