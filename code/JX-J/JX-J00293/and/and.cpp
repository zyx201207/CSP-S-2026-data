#include<bits/stdc++.h>
using namespace std;
int a[10001000];
int b[10000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }


    for(int i = 1;i <= 10000000;i++)
    {
        int m = max(b[i],b[i+1]);
    }
    for(int i = 1;i <= 10000000;i++)
        if(b[i] == m)
            cout << i;
    return 0;
}
