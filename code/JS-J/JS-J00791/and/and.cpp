#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],s=2147483647;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>n-m;i--){
        s=s&a[i];
    }
    cout<<s<<endl;
    return 0;
}
