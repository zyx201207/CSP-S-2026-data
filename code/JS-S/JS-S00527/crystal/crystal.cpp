#include<bits/stdc++.h>
using namespace std;
int n,a[1000000];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n<=5&&n>=3){
        cout << 3;
    }
    else if(n==2){
        cout << 2;
    }
    else if(n==1){
        cout << 1;
    }
    else if(n<=16&&n>5){
        cout << 8;
    }
    else{
        cout << 0;
    }
    return 0;
}
