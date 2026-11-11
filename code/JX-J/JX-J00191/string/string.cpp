#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[10000001], cnt, m=1;
char c[10000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    for(int i = n; i >= 1; i--)
    {
        if(c[i]!=c[m])
        {
            c[i]=c[m];
            cnt++;
            m++;
        }
    }
    cout << cnt;
    return 0;
}
