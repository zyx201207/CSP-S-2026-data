#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
long long a[200005];
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    ans=a[1];
    for(int i=2;i<=m;i++){
        if(ans&a[i])ans=ans&a[i];
        else m++;
    }
    cout<<ans;
    return 0;
}