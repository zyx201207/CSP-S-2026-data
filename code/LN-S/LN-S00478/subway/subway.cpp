#include<bits/stdc++.h>
using namespace std;
int w[1000005],a[1000005],t[1000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k;
    long long sum=0;
    while(n--){
        cin>>k;
        for(int i=1;i<=2*k;i++){
           cin>>a[i]>>t[i];
           sum+=t[i];
        }
    }
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
    }
    for(int i=1;i<=q;i++){
        cout<<w[x]+sum+w[y]<<endl;
    }
    return 0;
}
