#include <bits/stdc++.h>
using namespace std;

int main (){
    freopen("and1.in","r",stdin);
    freopen("and1.out","w",stdout);
    int n,m;
    int b=0;
    cin >>n >>m;
    int a[10005];
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(a[i]>a[i+1]){
                b=a[i];
                a[i]=a[i+1];
                a[i+1]=b;
            }
        }
    }
    cout <<a[m];
    return 0;
}
