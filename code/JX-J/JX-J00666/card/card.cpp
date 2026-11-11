#include</std.c++.h>
using namespace std;
int n,m,p[500005],pj[500005],js,sy[300005][3],dn[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            js=1;
            if(sy[p[j][1]==1 && js>sy[p[j]][2])js=sy[p[j]][2];
            else{
                if(pj[js+1]!=0){
                    sy[pj[j]][1]=0;
                }
                pj[js++]=p[j];
                sy[p[j]][1]=1;
                sy[p[j]][2]=js;
            }
        }
        for(int j=1;j<=js;j++){
            dn[pj[j]]++;
            sy[p[j][1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dn[i]<<" ";
    }

    return 0;
}
