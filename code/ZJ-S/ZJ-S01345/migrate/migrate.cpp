#include<bits/stdc++.h>
using namespace std;
int x[100000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int e=1;e<=t;e++){
        int n,d,bj;
        cin>>n>>d;
        bj=n;
        for(int j=1;j<=n;j++){
            cin>>x[j];
            if(x[j]-d>x[j-1]){
                bj=j-1;
            }
        }
        d+=d-1;
        cout<<x[bj]-x[1]-d+1;
    }    
    return 0;
}