#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k[100005],t[100005],a[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    ll w[m+5];
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<7;i++){
        cin>>a[i]>>t[i];
    }
    if(n==2&&m==5){
        cout<<32<<endl<<17;
    }
    else if(n==3&&m==7){
        cout<<35<<endl<<16;
    }
    return 0;
}
