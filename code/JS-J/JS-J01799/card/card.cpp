#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int zp[500005];
    for(int i=0;i<n;i++){
        cin>>zp[i];
    }
    int jg[n+1][n+1];
    for(int i=0;i<n;i++){
        int t=1;
        for(int j=i;j<n;j++){
            jg[i][t]=zp[j];
            int xb=1;
            while(jg[i][xb]!=zp[j])
                xb++;
            t=xb;
            jg[i][t++]=zp[j];
        }
        jg[i][0]=t;
    }
    for(int i=1;i<=m;i++){
        int gs=0;
        for(int j=0;j<n;j++){
            for(int p=1;p<jg[j][0];p++){
                if(jg[j][p]==i){
                    gs++;
                    break;
                }
            }
        }
        cout<<gs<<" ";
    }
    cout<<endl;
    return 0;
}
