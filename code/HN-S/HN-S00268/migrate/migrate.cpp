#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
int nxt[2000006],lst[2000006];
long long x[2000006];
int f[2000006];
int g[2000006];
int a[2000006];
long long ans=0;
int main(){
    // freopen("migrate.in","r",stdin);
    // freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }x[n+1]=2000000000000000001ll;
        x[0]=-2000000000000000001ll;
        for(int i=0;i<=n+1;i++){
            nxt[i]=lst[i]=f[i]=g[i]=a[i]=0;
        }
        for(int i=1,sua=0;i<=n;i++){
            nxt[i]=max(nxt[i-1],i);
            lst[i]=lst[i-1];
            while(x[nxt[i]+1]-x[i]<=d){
                nxt[i]++;
            }while(x[i]-x[lst[i]]>d){
                sua+=a[lst[i]];
                lst[i]++;
            }
            a[i]+=a[i-1];
            f[i]+=sua+1;
            if(nxt[i]>i){
                f[nxt[i]]+=f[i];
                a[i+1]+=f[i];
                a[nxt[i]]-=f[i];
            }

        }
        for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
        // for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";

    }
    return 0;
}
/*
0 1
4 2
1 2 3 4


*/