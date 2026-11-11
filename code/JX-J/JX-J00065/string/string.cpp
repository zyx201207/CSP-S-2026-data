#include<bits/stdc++.h>
using namespace std;
long long a[200005],pos = 1,cnt;
char c[200005];
string s0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        string s1(a[i],c[i]);
        s0 += s1;
    }
    string s1 = s0;
    reverse(s0.begin(),s0.end());
    if(s1 == s0){
        cout << 0;
        return 0;
    }
    for(int i = 0;i <= s1.length()/2;i++)
    {
        if(s1[i] != s0[i])cnt++;
    }
    cout << cnt;
    return 0;
}
