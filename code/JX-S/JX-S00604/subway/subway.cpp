#include<bits/stdc++.h>
using namespace std;
int a[1005],a1[2005][2005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>a1[i][j];
        }
    }
    while(q--){
        int qd,zd,cnt=0;
        cin>>qd>>zd;
        for(int j=1;j<=n;j++){
            for(int i=1;i<=2*k;i+=2){
                if(a1[j][i]==qd&&a1[j][i]==zd){
                    cnt+=a1[j][i+1];
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
