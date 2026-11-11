#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001];
int main()
{

    freopen("and,in","r",stdin);
    freopen("and,out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[5001];
        int sum = 0;
        sum = max(a[i] and a[i+1],a[i+1] and a[i+2]);
    }
    cout << sum;
    return 0;
}
