#include<bits/stdc++.h>
using namespace std;

const long long N = 5e5+5;
long long n,m;
long long a[N];
long long count(long long x,long long a[])
{
    long long ans = 0;
    for(int i = 0;i <= n;i++)
    {
        if(a[i] == x)   ans++;
    }
    return ans;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    long long ao = count(1,a);
    long long aq = count(1,a);
    if(m == 1)
    {
        cout << ao * n/2;
    }
    if(m==2)
    {
        cout << ao * n/2  <<  aq * n/2;
    }
    return 0;
}
