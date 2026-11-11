#include<bits/stdc++.h>
using namespace std;

int n , a[210000];
long long ans;
string b[210000];

int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 1 , j = n; i < j;)
    {
        if(b[i] != b[j]) ans += 1ll * min(a[i] , a[j]);
        if(a[i] < a[j])
        {
            a[j] -= a[i++];
        }
        else if(a[i] == a[j])
        {
            i++;
            j--;
        }
        else if(a[i] > a[j])
        {
            a[i] -= a[j--];
        }
    }
    cout << ans;
}
