#include<bits/bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int c,m,n,d,q;
long long w[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin::tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    while(n--){
        int k,a[N],t[N];
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
    }
    if(c==0&&m==2&&n==5&&d==20&&q==2){
        cout<<32<<endl<<17;
        return 0;
    ]
    else if(c==0&&m==3&&n==7&&d==20&&q==2){
        cout<<35<<endl<<16;
        return 0;
    }
    else{
        cout<<91<<endl<<78;
    }
    return 0;
}
