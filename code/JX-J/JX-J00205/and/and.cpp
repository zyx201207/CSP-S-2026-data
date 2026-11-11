#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long b[200005];
long long tot = 1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    tot = a[n];
    int j = n - 1;
    for(int i =  1 ;i <= m ;i++)
    {
        tot = tot & a[j];
        j--;
    }
    cout << tot;
    return 0;
}

