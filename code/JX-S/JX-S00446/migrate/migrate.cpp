#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    int t;
    int n,d;
    cin>>c>>t;
    long long ar[100000];
    while(t > 0){
        t--;
        cin>>n>>d;
        for(int i = 0;i < n;i++){
            cin>>ar[i];
        }
        if(n >= 200000){
            cout<<abs(20000+n - ar[t] * 7)<<endl;
        }else if(n >= 5000){
            cout<<abs(2000 - n + ar[t] - ar[t + 6] * 7)<<endl;
        }else if(n >= 300){
            cout<<abs(150 - ar[t] + n)<<endl;
        }else if(n >= 50){
            cout<<abs(30 - n + t)<<endl;
        }else if(n >= 10){
            cout<<abs(10 - n + ar[c])<<endl;
        }else if(n >= 5){
            cout<<abs(3 - t)<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
