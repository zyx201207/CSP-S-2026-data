#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    long long w[m];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=q;i++){
        int p=w[i]+w[i];
        cout<<p<<endl;
    }

    return 0;
}
