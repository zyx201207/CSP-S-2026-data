#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;

ll n,a[maxn];
string s;
ll ans=0;
ll inx=0;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin >> a[i] >> c;
        for(int j=1;j<=a[i];j++) s.push_back(c);
    }

    int len=s.size();

    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1])
        {
            ans++;
        }
    }

    cout << ans;


    return 0;
}


/*
2023/08/23 - 2026/10/31
Aetherius AFO
cout << "Bye World!";
Q.E.D
*/
