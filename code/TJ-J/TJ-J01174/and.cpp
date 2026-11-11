#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=a[n];
    for(int i=n;i>=n-(n-m);i--){
        s=(s&a[i]);
        cout<<a[i]<<endl;
    }
    cout<<s;
    return 0;
}
