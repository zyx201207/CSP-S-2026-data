#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        int a[1000005];
        for(int i=1;i<=x;i++){
            int z;
            cin>>z;
            a[i]=z;
        }
        if(x%2==0){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
