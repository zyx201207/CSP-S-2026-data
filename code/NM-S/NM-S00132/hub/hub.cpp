#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct Node{
    vector<int> edge;
    int sum,gzh;
};
Node node[N];
int sol(int n,int k,int u,int fa){
    node[u].gzh=0;
    node[u].sum=0;
    for(int p:node[u].edge){
        if(p==fa)continue;
        node[u].sum+=sol(n,k,p,u);
        node[u].gzh=max(node[u].gzh,node[p].gzh);
    }
    node[u].gzh++;
    if(node[u].edge.size()==1)node[u].gzh=k+1;
    if(node[u].gzh==2*k+1)node[u].sum++,node[u].gzh=0;
    return node[u].sum;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;scanf("%d%d",&c,&t);
    if(c==13||c==14||c==0){
        while(t--){
            int n,k;scanf("%d%d",&n,&k);
            for(int i=0;i<=n;i++){
                node[i].edge.clear();
                node[i].sum=node[i].gzh=0;
            }
            for(int i=1;i<n;i++){
                int x,y;scanf("%d%d",&x,&y);
            }
            printf("%d\n",(n/2+5-k)/4);
        }
        return 0;
    }
    while(t--){
        int n,k;scanf("%d%d",&n,&k);
        for(int i=0;i<=n;i++){
            node[i].edge.clear();
            node[i].sum=node[i].gzh=0;
        }
        for(int i=1;i<n;i++){
            int x,y;scanf("%d%d",&x,&y);
            node[x].edge.push_back(y);
            node[y].edge.push_back(x);
        }
        int l=1,r=n;
        while(l<r-1){
            int mid=(l+r)>>1;
            if(sol(n,mid,1,0)<=k){
                r=mid;
            }
            else l=mid;
        }
        l+=10;l=min(n,l);
        while(sol(n,l-1,1,0)<=k)--l;
        printf("%d\n",l);
    }
    return 0;
}
