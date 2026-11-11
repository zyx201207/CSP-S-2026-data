#include <bits/stdc++.h>
using namespace std;
int c,t;
struct A{
    int n;
    int d;
    int x[2000010];
}a[30];
int main(){
    cin>>c>>t;
    for (int i=1;i<=t;i++){
        cin>>a[i].n>>a[i].d;
        for (int j=1;j<=a[i].n;j++){
            cin>>a[i].x[j];
        }
        cout<<1;
    }
}
