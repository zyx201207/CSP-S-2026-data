#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=300005;
int n,m,px[MAXN],ans[MAXM],q[MAXN],lens=0;
bool findf(int x){
    for(int i=1;i<=lens;i++) if(q[i]==x) return 1;
    return 0;
}
int findw(int x){
    for(int i=1;i<=lens;i++) if(q[i]==x) return i;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>px[i];
    for(int z=1;z<=n;z++){
        memset(q,0,sizeof(q));
        for(int i=z;i<=n;i++){
            if(findf(px[i])==1){
                for(int j=lens;j>=findw(px[i]);j--) q[j]=0;
                lens=findw(px[i]);
            }
            lens++;
            q[lens]=px[i];
        }
        for(int i=1;i<=lens;i++) ans[q[i]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
;}
