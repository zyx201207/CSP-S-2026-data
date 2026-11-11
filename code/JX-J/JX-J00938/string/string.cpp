#include <bits/stdc++.h>
using namespace std;
int a[10000005];
char b[10000005];
int main(){
    int n,x=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n/2;i++){
        x+=a[i];
    }
    cout<<x;
    return 0;
}
