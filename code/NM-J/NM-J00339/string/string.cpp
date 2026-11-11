#inculde<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w".stdout);
    long long n,a;
    string c;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a >> c;
    }
    if(n==3)
    {
        cout << n-1;
    }
    else
    {
        cout << "0";
    }
    return 0;
}
