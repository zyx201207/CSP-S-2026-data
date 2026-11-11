#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[N],pos[M],ans[M];
inline void play(int s){
    int p=0;
    for(int i=s;i<=n;i++){
        if(!pos[a[i]]||pos[a[i]]>p){
            p++;
            if(pos[b[p]]>=p)pos[b[p]]=0;
            b[p]=a[i];
            pos[b[p]]=p;
        }else p=pos[a[i]];
    }for(int i=1;i<=p;i++)ans[b[i]]++;
}int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)play(i);
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}