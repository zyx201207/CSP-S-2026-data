#include <bits/stdc++.h>
using namespace std;
int a[100000001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int max=-1;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        if(max>a[i])
            max=a[i];
    }
    cout<<a[i];
}

