#include <bits/stdc++.h>
using namespace std;

long long a,n,cnt=0,len;
string s,t;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a >> t;
        for (int i=1;i<=a;i++){
            s+=t;
        }
    }
    len = s.length();
    for (int i=0;i<=((len-1)/2);i++){
        if (s[i] != s[len-i-1]) cnt++;
        else continue;
    }
    cout << cnt;
    return 0;
}
