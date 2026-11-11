#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long ma,n,m,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ma=max(ma,a[j]);
        }
    }
    cout<<ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
