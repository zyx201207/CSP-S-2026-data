#include <bits/stdc++.h>
using namespace std;
/*
struct AAA{
    int a[1000];
    int t[1000];
}k[10000];

struct BBB{
    int x;
    int y;
}xy[100005];
*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    
    if(c>=7&&c<=11){
        int nn=n;
        int w[10000];
        int a1[10000];
        int a2[10000];
        int t1[10000];
        int t2[10000];
        for(int i = 1;i<=m;i++){
            cin>>a[i];
        }
        for(int i = 1;i<=nn;i++){
            int lsls;
            cin>>lsls;
            if(lsls!=2){
                for(int j = 1;j<=lsls;j++){
                    int ls1,ls2;
                    cin>>ls1>>ls2;
                    i--;
                    nn--;
                }
                continue;
            }
            cin>>a1[i]>>t1[i]>>a2[i]>>t2[i];
            for(int i = 1;i<=q;i++){
                int qd,zd;
                cin>>qd>>zd;
                int cnt=0;
                int mi = 1e9;
                for(int j = 1;j<=nn;j++){
                    if(a1[j]==zd){
                        int dc=zd;
                        while(1){
                            cnt+=t1[j];
                            if(a)
                            dc=a2[j];
                            cnt+=t2[j];
                        }
                        
                    }
                }
            }

        }
    }
    /*
    int w[10000];
    for(int i = 1;i<=m;i++){
        cin>>a[i];
    }
    int K;
    for(int i = 1;i<=n;i++){
        cin>>K;
        for(int j = 1;j<=k;j++){
            cin>>k[i].a[j]>>k[i].t[j];
        }
    }
    for(int i = 1;i<=q;i++){
        cin>>xy[i].x>>xy[i].y;
        int cnt =0;

    }
    */
    return 0;
}