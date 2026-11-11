#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        mx=max(mx,a);
    }
    cout<<mx;
    return 0;
}
