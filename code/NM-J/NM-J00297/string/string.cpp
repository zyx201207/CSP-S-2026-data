#include<bits/stdc++.h>
using namespace std;

long long  n;
string sum,s2;
int ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long  i = 1;i<=n;i++)
    {
        long long  m =0;
        cin >> m;
        string s1;
        cin >> s1;
        for(long long i =1;i<=m;i++)
        {
            sum += s1;
        }
    }
    for(long long i = sum.size()-1;i>=0;i--)
    {
        s2 += sum[i];
    }
    if(s2 == sum)
        cout << "0";
    else
    {


        int len = sum.size();
        int l = len/2-1;
        for(long long i =0;i<=l;i++)
        {
            if(sum[i] == s2[i])
                continue;
            else
                ans++;
        }
        cout << ans;
    }

    return 0;
}
