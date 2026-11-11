#include <bits/stdc++.h>
using namespace std;

int n,cnt=0,ans=0;
char c;
long long a;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while(n--)
    {
        cin >> a >> c;
        cnt+=a;
        while(a--)
            s+=c;

    }
    for(int i=0;i<cnt/2;i++)
    {
        if(s[i]!=s[cnt-i-1])
            ans++;
    }
    cout << ans;
    return 0;
}

