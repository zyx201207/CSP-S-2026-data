#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,c[500860],d;
    cin >> a>>b;
    for(int i = 1;i<=a;i++){
        cin >>c[i];
    }
    sort(c+1,c+a+1);
    d = c[a];
    for(int i = a-1;i>=a-b+1;i--){
        d&=c[i];
    }
    cout <<d;
    return 0;}
