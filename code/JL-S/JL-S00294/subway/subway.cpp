#include<bits/stdc++.h>
using namespace std;
int s
int c[110];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,q,d;
    cin>>c>>n>>m>>q>>d;
    for(int i=1;i<=m;i++){
        cin>>c[i];
        s+=c[i];
    }
    cout<<s;
    return 0;
}
