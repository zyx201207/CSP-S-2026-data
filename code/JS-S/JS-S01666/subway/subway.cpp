#include <bits/stdc++.h>
using namespace std;
struct ML{
    int sn;
    int wt;
};
struct SS{
    int k;
    ML ml[125250];
};
int lf(SS a,int b){
    for(int j=0;j<a.k;j++){
        if(a.ml[j].sn==b){
            return j+1;
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    SS ss[n];
    for(int i=0;i<n;i++){
        cin>>ss[i].k;
        for(int j=0;j<ss[i].k;j++){
            cin>>ss[i].ml[j].sn>>ss[i].ml[j].wt;
        }
    }
    for(int q0=0;q0<q;q0++){
        int x,y;
        cin>>x>>y;
        int tmp;
        for(int i=0;i<n;i++){
            int x1=lf(ss[i],x);
            int y1=lf(ss[i],y);
            if(x1){
                if(y1){
                    cout<<w[ss[i].ml[x1-1].sn-1]+w[ss[i].ml[y1-1].sn-1]+ss[i].ml[x1-1].wt+ss[i].ml[y1-1].wt;
                    break;
                }
            }
        }
    }
    return 0;
}
