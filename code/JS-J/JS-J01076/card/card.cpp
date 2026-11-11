#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
vector<int>gv[N];
int n,m,a[N],lst[N],sm[N],deg[N],que[N],tt;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(lst[a[i]]!=i){
            gv[i].push_back(lst[a[i]]);
            deg[lst[a[i]]]++;
        }else{
            gv[i].push_back(i+1);
            deg[i+1]++;
        }
    }
    for(int i=1;i<=n;i++){
        sm[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            que[++tt]=i;
        }
    }
    for(int i=1;i<=tt;i++){
        for(int j:gv[que[i]]){
            sm[j]+=sm[que[i]];
            if((--deg[j])==0){
                que[++tt]=j;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",sm[lst[i]]);
    }
    return 0;
}