#include <bits/stdc++.h>
using namespace std;

int a[500005], num[300005], desk[500005], r;
int on_desk(int k)
{
    for(int i=1; i<=r; i++)
        if(k==desk[i])
            return i;
    return 0;
}
void game(int i, int n)
{
    r = 0;
    for(int j=i; j<=n; j++)
    {
        int k = a[j];
        int pos = on_desk(k);
        if(pos)
            r = pos;
        else
        {
            r++;
        	desk[r] = k;
        }
    }
    for(int j=1; j<=r; j++)
        num[desk[j]]++;
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        game(i, n);
    for(int i=1; i<=m; i++)
        cout << num[i] << " ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
