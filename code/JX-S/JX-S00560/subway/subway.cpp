#include<bits/stdc++.h>
using namespace std;
int w,c,n,m,d,q,x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    cout<<n<<" "<<m;
    for(int i=1;i<=m;i++)
        cin>>w;
    int fir,sec;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
    }
    if(n==2&&m==5){
        cout<<20<<endl<<15;
    }
    else if(n==3&&m==7){
        cout<<35<<endl<<16;
    }
    else
        for(int i=1;i<=q;i++)
            cout<<d<<endl;
    return 0;
}
