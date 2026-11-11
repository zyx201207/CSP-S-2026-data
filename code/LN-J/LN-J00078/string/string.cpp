#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int cnt;
    long long mj,n,s;
    char x;
    string m,k;
    mj = 0;
    cin >> n;
    cnt = 0 ;
    for(int i = 1;i <= n;i++)
    {
        cin >> s >> x;
        for(int j = 1;j <= s;j++)
        {
            m += x;
        }
        mj +=  s;
    }
    k = m;

    for(int i = 0; i <= (mj-1) / 2;i++)
    {
        k[mj-i-1] = k[i];
        if(k[mj-i-1] != m[mj-i-1])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
