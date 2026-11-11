#include<bits/stdc++.h>
using namespace std;
long long x[2000001]={};
int Dp(int n,int d){
    if(n==1){
        return 1;
    }
    else{
        return dp(n-1)*d;
    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;++i){
        long long n,d;
        cin>>n>>d;
        x[2000001]={};
        for(int j=1;j<=n;++j){
            cin>>x[j];
        }
        Dp(n,d);
    }
    return 0;
}
