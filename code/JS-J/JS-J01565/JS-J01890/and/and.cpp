#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=n-1;i>=n-m+1;i--) ans=ans&a[i];
    printf("%d",ans);
    return 0;
}
