#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],k,k2[500005],e,f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    while(q--){
        cin>>k;
        for(int i=1;i<=k*2;i++){
            cin>>k2[i];
        }
        cin>>e>>f;

    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
