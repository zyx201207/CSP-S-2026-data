#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    long long a[1000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+n+1,a+1);
    for(int i=1;i<=m;i++){
        x=a[i]&&a[i+1];
    }
    cout<<x<<endl;
    return 0;
}
