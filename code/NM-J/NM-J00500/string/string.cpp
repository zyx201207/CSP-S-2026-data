#include <bits/stdc++.h>
using namespace std;
int c[1000000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int num=0,ans = 0;
    cin >> n;
    char b = b;
    for(int i = 1;i <= n;i++)
    {
        int a;
        cin >> a;
        char x;
        cin >> x;
        for(int j = 0;j < a;j++){
            int l=x-b;
            c[i+j] = l;
        }
    }
    for(int i = 1;i <= num;i++)
    {
        for(int j = num;j >= 1;j--)
        {
            if(c[i] != c[j])
            {
               ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
