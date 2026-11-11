#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Q=100005;
LL c,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    LL n[Q],d[Q],x[Q];
    int mx=0,xm=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>d[i];
        for(int i=1;i<=n[i];i++){
            cin>>x[i];
        }
    }
    for(int i=1;i<=n[i];i++){
        for(int j=1;j<=n[i];i++){
            if(-x[i]+x[j]<=d[i]||-x[i]+x[j]<=d[i]){
                mx=mx+1;
            }
        }
        if(mx==2){
            xm++;
        }
    }
    cout<<xm;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
