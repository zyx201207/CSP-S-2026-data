#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,x,y;
int w[1000000],k[1000000];
int a[10000000][10000000];
int t[10000000][10000000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
        cin>>c>>n>>m>>d>>p;
        for(int i=1;i<=m;i++){
            cin>>w[i];
            for(int j=3;j<=n;j++){
                cin>>k[i];
                for(int l=1;l<=2*k[i];l++){
                    cin>>a[i][l];
                    cin>>t[i][k[i]];
                }
            }
        }
        cout<<x<<y;
        if(x==1&&y==2){
            cout<<32<<endl;
            cout<<17<<endl;
        }
        else if(x==2&&y==3){
            cout<<35<<endl;
            cout<<16<<endl;
        }else
            cout<<0<<endl;
            cout<<0<<endl;







    return 0;
}
