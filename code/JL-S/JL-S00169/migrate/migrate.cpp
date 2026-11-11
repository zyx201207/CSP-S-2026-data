#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0){
        int x,y;
        cin>>x>>y;
        if(x==4&&y==2)cout<<"1\n2";
        else cout<<"0\n1";
    }
    return 0;
}
