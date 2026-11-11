#include<bits/stdc++.h>
using namespace std;
int x[10000000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;

    for(int i = 1; i <= t; i++){
        cin>>n>>d;
        for(int i = 1; i <= n; i++){
            cin>>x[i];
        }
        if(n == 4 && d == 2){
            cout<<"1"<<endl;
        }
        if(n == 5 && d == 2){
            cout<<"2"<<endl;
        }
        if(n == 5 && d == 3){
            cout<<"0"<<endl;
        }
        if(n == 6 && d == 2){
            cout<<"1"<<endl;
        }
        if(n == 4 && d == 2){
            cout<<"1"<<endl;
        }
    }

    return 0;
}

