#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return r*f;
}
int a[2000005],n,m,ans,cnt,num=LONG_LONG_MAX;
void dfs(int x,int z,int numm){
    if(x==z){
        if(numm==num){
            cnt++;
        }
        else{
            if(numm<num){
                cnt=1;
                num=numm;
            }
        }
        return;
    }
    for(int i=x+1;i<=z;i++){
        if(a[i]-a[x]>m) break;
        dfs(i,z,numm+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c=read();
    t=read();
    while(t--){
        n=read();
        m=read();
        ans=0;
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                num=LONG_LONG_MAX;
                cnt=0;
                dfs(i,j,0);
                if(cnt==2) {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
