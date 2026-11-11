#include<bits/stdc++.h>
using namespace std;
int n;
long a[200005];
char c[200005];
int main()
{
    freopen(string.in,"r",stdin);
    freopen(string.out,"w",stdout);
    cin >> n;
    string s;
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while(l <= n / 2 && r >= n / 2)
    {
        if(c[l] != c[r])
        {
            int k = min(a[l], a[r]);
            cnt += k;
            a[l] -= k;
            a[r] -= k;
            if(a[l] == 0) l+=1;
            if(a[r] == 0) r-=1;
        }
    }
    cout << cnt;
    return 0;
}
