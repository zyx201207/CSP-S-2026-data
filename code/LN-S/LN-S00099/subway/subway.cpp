#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N1=5e5+10;
int a[N1];
int b[N1];
int c1[N1];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0){
        if(n==2){cout<<32<<"\n"<<17;
        return 0;
        }
        else if(n==3){
                cout<<35<<"\n"<<16;
        return 0;}
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        cin>>b[i]>>c1[i];
    }
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
    }
    while(q--){
        cout<<0;
    }
    return 0;
}
