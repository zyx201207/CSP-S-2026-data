#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int minn = INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int last = a[i]&a[j];
            minn = min(minn,last);
        }
    }
    cout<<minn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
