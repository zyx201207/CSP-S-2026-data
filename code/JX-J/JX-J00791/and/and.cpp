#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],maxx=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    maxx=a[n];
    for(int i=n-1;i>n-m;i--)
    {
        maxx=maxx&a[i];
    }
    cout<<maxx;
    return 0;
}
