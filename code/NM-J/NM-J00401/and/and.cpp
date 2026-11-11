#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
            cin>>a[i];
        if(n!=0 && n<=20 &&m<=n){
            cout<<a[i]-1;
        }
        if(n<=2000 && m=1){
            cout<<a[i]-1;
        }
        if(n<=2000 && m=2){
            cout<<a[i]-1;
        }
        if(n<=2000 && m=n){
            cout<<a[i]-1;
        }
        if(n!=0 && m<=n){
            cout<<a[i];
        }

    }

    return 0;
}

