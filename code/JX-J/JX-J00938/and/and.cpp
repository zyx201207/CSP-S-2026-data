
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    int n,m,x=-999999999;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i] and a[j]>x){
                x=a[i] and a[j];
            }
        }
    }
    cout<<x;
    return 0;
}
