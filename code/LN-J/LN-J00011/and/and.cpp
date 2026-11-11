#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a;
    cin>>n>>a;
    long long b[n+1]={0};
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<b[n-1];
    return 0;
}

