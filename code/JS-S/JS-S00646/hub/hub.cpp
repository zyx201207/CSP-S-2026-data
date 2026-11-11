#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
const int MAXN=1000006;
vector<int>e[MAXN];
unsigned long long slove(){
    unsigned int a[MAXN];
    unsigned long long res;
    bool b=0;
    for(int i=1;i<=(n,k);i++){
        if(a[i]%3==1)res=a[i]*res;
        else if(a[i]%3==2)res+=a[i];
        else b=1;
    }
    if(b=1)res=0/0;
    return res;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    unsigned long long ans=slove();
    printf("%lld\n",ans);
    return 0;
}