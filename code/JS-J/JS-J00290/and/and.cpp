#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int mx=0;
    for(int i=0;i<n-m+1;i++){
        for(int j=i+1;j<n;j++){
            mx=max(a[i]&a[j],mx);
        }
    }
    cout<<mx;
    return 0;
}
