#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int c[500010];
int ct;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(ct<n){
        for(int i=1;i<=n;i++){
        b[i]=a[i];
        for(int j=1;j<=i;j++){
            if(b[j]==b[i]){
                for(int k=j+1;k<=i;k++){
                    b[k]==0;
                }
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]==i) c[i]++;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i+1];
    }
    ct++;
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<endl;
    }
    return 0;
}
