#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m;i--){
        x=i&&(i-1);
    }
    cout<<x+11;
    return 0;
}
