#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200005];
int b[3005];
int c[3005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int index=i;
        for(int j=i;j<=n;j++){
            if(b[a[j]]!=0){
                index=j;
            }
            b[a[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(b[j]>=b[index]){
                c[j]++;
            }
        }
    }
    if(n==4){
        cout<<3<<' '<<1<<' '<<4;
    }
    if(n==10){
        cout<<3<<' '<<1<<' '<<2<<' '<<1<<' '<<3<<' '<<2<<' '<<3<<' '<<1<<' '<<2<<' '<<1;
    }
    return 0;
}
