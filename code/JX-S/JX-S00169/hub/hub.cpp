#include <bits/stdc++.h>
using namespace std;
int a[500005];
void qian(int n,int d){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d || j-i<=2) continue;

        }
    }
}
int main(){
    int c,t;
    int n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
            cin>>n>>d;
        qian(n,d);
    }
    return 0;
}
