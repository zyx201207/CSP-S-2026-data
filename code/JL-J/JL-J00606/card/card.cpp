#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card","r",stdin);
    freopen("card","w",stdout);
    int n,m,a[10001],b[10001];
    cin >> n >> m;
    for(int j=1;j<=n;j++)
    {
        cin >> a[j];
    }
    for(int i = 1;i <= m;i++)
    {
        cout << b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
