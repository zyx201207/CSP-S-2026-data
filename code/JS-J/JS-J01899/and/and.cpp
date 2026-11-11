#include<bits/stdc++.h>
#define N 110000000
using namespace std;


int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s=-1,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=max(a[i],s);
    }
    cout<<s;
    return 0;




}