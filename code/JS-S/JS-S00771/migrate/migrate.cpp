#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e6+5;
int c,t,n,d,a[N],f[N];
bool check(int x,int y){
    int i,tmp;
    for(i=x;i<=y;){
        tmp=a[i]+d;
        if(tmp>a[y])break;
        while(a[i]<tmp)i++;
    }
    //cerr<<"x: "<<x<<" y: "<<y<<" tmp: "<<tmp<<'\n';
    if(a[y]-(tmp-d)!=d-1){
        return 0;
    }return 1;
    //return a[y]-a[x]==2*d-1;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%llu%llu",&c,&t);
    while(t--){
        //cerr<<"t: "<<t<<'\n';
        scanf("%llu%llu",&n,&d);
        //cerr<<n<<" "<<d<<'\n';
        if(n<=2){
            printf("0\n");
            continue;
        }
        bool dengcha=1;
        for(int i=1;i<=n;i++){
            scanf("%llu",a+i);
            if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]){
                dengcha=0;
            }
        }
        //cerr<<"shushu\n";
        //cerr<<n<<" "<<d<<'\n';
        /*
        if(dengcha){
            int sdf=d/(a[2]-a[1]);
            if(sdf<=1){
                printf("0\n");
                continue;
            }
            //memset(f,0,sizeof f);
            //f[1]=f[2]=1;
            //int id=0;
            for(int i=2*d-1;i<=n;i++){
                for(int j=1;j<=sdf;j++){
                    f[i]+=f[i-j];
                }
                //if(!id && f[i]==2)id=i;
            }
            printf("%lld\n",1ll);
        } else{
        */
        /*
            int up=0;
            for(int i=1;i<=n;i++){
                if(a[i]-a[i-1]>d){
                    up=i;
                }
            }
        */
            int ans=0;
            for(int i=1;i<=n-3;i++){
                for(int j=i+3;j<=n;j++){
                    //cerr<<i<<" "<<j<<'\n';
                    ans+=check(i,j);
                    //if(check(i,j)){
                    //   cerr<<i<<" "<<j<<'\n';
                    //}
                }
            }
            //cerr<<"here\n";
            //cerr<<"ans: "<<ans<<'\n';
            printf("%llu\n",ans);
            //cerr<<"asdf\n";
        //}
    }
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
