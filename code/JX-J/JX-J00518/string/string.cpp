#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n;
bool f = 0;
char c[N],k;
ll a[N],ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i] >> c[i];
        for(int j = 1 ; j <= a[i] ; j++) s += c[i];
        if(k != c[i]) f = 0;
    }
    if(f == 1)
    {
        cout << "0\n";
        return 0;
    }
    for(int i = 0 ; i < int(s.size())/2; i++)
    {
        if(s[i]!= s[n-i-1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
