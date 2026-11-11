#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int q=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        q+=a[i];
    }
    if (n==1){
        cout<<0;
    }else{
        cout<<n/2;
    }
    return 0;
}
