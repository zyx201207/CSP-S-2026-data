#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200020],ans,bns;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    bns = -1;
    //sort(a+1,a+n+1);
    //bns = -1;
    //do
    //{
        //for(int i = 1; i<=n; i++)
            //cout << a[i] << " ";
        //cout << endl;
        //ans = a[1];
        //for(int j = 2; j<=m; j++)
        //{
         //   ans = ans&a[j];
        //}
        //bns = max(ans,bns);
    //}
    //while(next_permutation(a+1,a+n+1));
    //cout << bns;
    for(int j = 1; j<=n-m+1; j++)
    {
        //ans = a[j];
        for(int x = j+1; x<=n; x++)
        {
            ans = a[j]&a[x];
            //cout << ans << endl;
            bns = max(ans,bns);
        }
        //cout << ans << endl;
        //bns = max(ans,bns);
    }
    cout << bns;
    return 0;
}
