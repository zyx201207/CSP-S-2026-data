#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
    freopen("and.in","r","std.in);
    freopen("and.out","w","std.out");
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }if(a[i]>a[i+1]){
        cout<<a[i];
    }else
    cout<<a[i+1];
    return 0;
}


