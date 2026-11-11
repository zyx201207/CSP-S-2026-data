#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        int a;
        for(int j=0;j<n;j++){
            cin>>a;
        }
        if(n%2==0){
            cout<<1;
        }
        else{
            cout<<2;
        }
    }
    return 0;
}
