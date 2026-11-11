#include <bits/stdc++.h>
using namespace std;
int b[500005],vis[6],vis2[6],alive[6],ans[6];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n-1;i++)
    {
        if(a[i] != a[i+1])
        {
            b[a[i]] = i;
        }
    }
    int x = 1;
    while (b[x] != 0)
    {
        cout << b[x] << " ";
        x++;
    }
    return 0;
}
