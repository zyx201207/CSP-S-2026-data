#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000005],time1;
int a[1000005],t[1000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=q;i++){
        int x=0,y=0;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int i=1;i<=k;i++){
                cin>>a[i];
                cin>>t[i];
            }
            for(int i=1;i<=k;i++){
                if(a[i]==x){
                    for(int j=1;j<=i;j++){
                        time1+=t[j]+w[a[i]];
                    }
                }
                if(a[i]==y){
                    for(int j=1;j<=i;j++){
                        time1+=t[j]+w[a[i]];
                    }
                }
            }
        }
    }

    return 0;
}
