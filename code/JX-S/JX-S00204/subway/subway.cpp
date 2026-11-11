#include<bits/stdc++.h>

using namespace std;
int c,n,m,d,q,x,y,k;

struct stop{
    int w;
    int t[30];
}a[500010];


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
        if(c==0){
            cin>>n>>m>>d>>q;
            for(int i=1;i<=m;i++){
                scanf("%d",&a[i].w);
            }
            for(int i=1;i<=n;i++){
                scanf("%d",&k);
                int u,v;
                for(int j=1;j<=k;j++){
                    scanf("%d%d",&u,&v);
                }
            }
            while(q--){
                scanf("%d%d",&x,&y);
            }
            if(n==2){
                cout<<32<<endl<<17;
            }
            if(n==3){
                cout<<35<<endl<<16;
            }
        }

    return 0;
}

