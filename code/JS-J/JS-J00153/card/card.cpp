#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[100005];
    for(int j = 0;j < n;j++)
    {
        cin >> a[j];
    }
    bool is = true;
    for(int i = 0;i < m;i++)
    {
        for(int j = n-i;j < n;j++)
        {
            if(a[j] != a[j+1])
            {
                is = false;
            }
        }
        if(is == true) cout << i+1 << " ";
        else if(is == false&&i == m-1) cout << n << " ";
        else if(is == false&&i != m-1)is = true;
    }
    return 0;
}
