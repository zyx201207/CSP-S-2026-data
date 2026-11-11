#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],num;
string t;
char s;
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i] >>s;
        for(int j=num+1;j<=num+a[i];j++)
        {
            t[j]=s;
        }
        num+=a[i];
    }
    for(int i=1;i<=num/2;i++)
    {
        if(t[i]!=t[num-i+1])
        {
            cnt++;
        }
    }
   cout << cnt;
   return 0;
}
