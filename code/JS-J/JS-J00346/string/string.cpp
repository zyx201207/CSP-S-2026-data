#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for(int i=1;i<=a;i++)
            s+=c;
    }
    int l = s.size()/2,ans=0;
    for(int i=0;i<l;i++)
        if(s[i] != s[s.size()-i-1]) ans++;
    cout << ans;
    return 0;
}
