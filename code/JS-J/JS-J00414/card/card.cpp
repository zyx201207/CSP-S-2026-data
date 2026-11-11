#include<bits/stdc++.h>
using namespace std;

int cnt(int a[])
{
    int jsq = 0;
    for(int i=1; i<=200; i++)
    {
        if(a[i] != 0) jsq++;
    }
    return jsq;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, r, a[200], b[200], ans = 0, k, t[200];
    cin >> n >> r;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        k=0;
        for(int j=i; j<=n; j++)
        {
            k++;
            b[k] = a[j];
            int len = cnt(b);
            for(int q=1; q<len; q++)
            {
                if(b[q] == a[j])
                {
                    for(int p=q+1; p<=k; p++)
                    {
                        b[p] = 0;
                    }

                    cout << k << endl;k = cnt(b);
                }
            }
        }
        for(int j=1; j<=cnt(b); j++)
        {
            //cout << b[j] << endl;
            t[b[j]++];
        }
        memset(b, 0, sizeof b);
    }
    for(int i=1; i<=r; i++)
    {
        cout << t[i] << endl;
    }
    return 0;
}
