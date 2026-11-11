#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[m];
   return 0;
}
