#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[100005];
    for(int i=1;i<=n;i++){
        int zanshi;
        cin>>zanshi;
        a[i]=zanshi;
    }
    int q=0;
    int ee=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-1;j++){
            ee = a[i]&a[j]&a[i+1]&a[j+1];
            q = max(ee,q);
        }
    }
    cout<<q;
    return 0;
}
