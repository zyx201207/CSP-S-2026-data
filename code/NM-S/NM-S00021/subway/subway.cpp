#include<iostream>
using namespace std;
const int N=5*1e5+10,M=510;
int c,m,w[N],n,d,q,t[M][N];
bool a[M][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];//exit to zhantai
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int jg;
            cin>>jg>>t[i][jg];
            a[i][jg]=true;
        }
    }
    while(q--){
        int x,y,ans=0;
        cin>>x>>y;
        ans+=w[x]+w[y];
        //20 21 ceshidian
        if(n==2){
            if((a[1][y]&&a[1][x])&&(a[2][y]&&a[2][x])){
                cout<<min(ans+t[1][y]+t[1][x],ans+t[2][y]+t[2][x])<<endl;
            }else if(a[1][x]&&!a[1][y]/*||a[2][x]&&!a[2][y]*/){
                int tmp=1e10;
                for(int i=x+1;i<=y-1;i++){
                    tmp=min(tmp,t[1][i]+t[2][i]);
                }
                cout<<ans+tmp+t[1][x]+t[2][y]<<endl;
            }else if(a[2][x]&&!a[2][y]){
                int tmp=1e10;
                for(int i=x+1;i<=y-1;i++){
                    tmp=min(tmp,t[1][i]+t[2][i]);
                }
                cout<<ans+tmp+t[1][y]+t[2][x]<<endl;
            }else if(a[1][x]&&a[1][y]){
                cout<<ans+t[1][x]+t[1][y]<<endl;
            }else{
                cout<<ans+t[2][x]+t[2][y]<<endl;
            }
            //tai nan le qwq;
            //lei ting pian fen shi shan dai ma;
        }
    }
    return 0;
}
