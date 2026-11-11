#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],cnt[100010],vis[N];
inline int read(){
    int x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch==EOF) return 0;
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
        if(ch==EOF) break;
    }
    return x*f;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
        for(int i=1;i<=n;i++){
            fill(vis+1,vis+1+n,1);
            for(int j=i;j<=n;j++){
                //cnt[a[j]]++;
                int f=0,k;
                for(k=j-1;k>=i;k--) if(a[k]==a[j]&&vis[k]) {f=1;break;}
                if(f) for(int z=k;z<j;z++) {vis[z]=0;}//cnt[a[z]]--;
            }
            for(int j=i;j<=n;j++) if(vis[j]) cnt[a[j]]++;
        }
        for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
    return 0;
}
