#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t>=1){
        t--;
        int n,d;
        cin>>n>>d;
        int x,y;
        cin>>x>>y;
        for(int i=3;i<=n;i++){
            int m;
            cin>>m;
        }
        int m=y-x,ct=0;
        if(m>=d||2*m>d){
            cout<<0<<endl;
        }else {
            for(int i=2;i<=d/m;i++){
                for(int j=1;j<=(n-1)%i;j++) {
                    ct+=j;
                }
            }
            cout<<ct;
        }
    }
    return 0;
}
