#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int z=1;z<=t;z++){
        int n,d,sum;
        cin>>n>>d;
        int x[n+10]={};
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(x[n]-x[1]<=d)
            cout<<0;
        for(int i=n;i>=1;i--){
            sum=0;
            for(int j=n-d-1;j>=1;j--){
                for(int q=d;q>=1;q--){

                }

            }
        }
    }
    return 0;
}
