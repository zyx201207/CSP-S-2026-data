#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int s,h;
    cin>>s>>h;
    int a[10000];
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    for(int i=1;i<s;i++){
        if(i%2==1) cout<<a[i]+a[i-1];
        else cout<< a[i]-a[i-1];
    }
    return 0;
}
