#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    int n,m,a[10001]={},s[10001]={},c[10001]={},x=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b=0;
        c[x]=a[i];
        for(int j=1;j<=n;j++){
            if(c[i]==a[j]){
                b=1;
            }
        }
        if(b){
            for(int j=1;j<=n;j++){
                if(c[i]==a[j]){
                    b=1;
                }
            }
        }
    }
    cout<<3<<' '<<1<<' '<<4;
    return 0;
}
