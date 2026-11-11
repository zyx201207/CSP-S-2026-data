#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++)cin >>a[i];
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=1;i<=m;i++){
        ans=ans&a[n-m+1];
    }
    cout <<ans;
    return 0;
}
