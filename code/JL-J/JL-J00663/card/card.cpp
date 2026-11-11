#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<a[i]%i;
    }
    return 0;
}
