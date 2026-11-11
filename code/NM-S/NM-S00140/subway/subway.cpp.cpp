#include<bits/stdc++.h>
using namespace std;
int cnt;
long long c,n,m,d,q;
long long w[100005],k[100005],r[100005],t[100005];
long long x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i]>>k[i]>>t[i];
    }
    for(int i=1;i<=q;i++){
        cin>>r[i];
        x=r[1];
        y=r[q]
    }
    for(int i=1;i<=q;i++){
        cnt=w[x]+t[x]+t[y]+w[x];
        for(int j=1;j<=q;j++){
            cout<<cnt<<endl;
        }
    }
    return 0;
}
