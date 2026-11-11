#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int INF=0x3f3f3f3f;
struct Node{
    int val;
    long long sum;
    bool operator < (const Node &a) const{
        return val<a.val;
    }
};
struct Item{
    int f;
    long long g;
}f[N][N];
int C,T,n,ans;
long long x[N],m;
set<Node> st;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%lld",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
        // cout<<"OK"<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                f[i][j]={INF,0};
            f[i][i]={0,1};
        } ans=0;
        for(int l=1;l<=n;l++){
            int ll=l;
            st.clear();
            st.insert(Node{0,1});
            for(int r=l+1;r<=n;r++){
                int ls=lower_bound(x+1,x+n+1,x[r]-m)-x;
                for(int i=ll;i<ls;i++){
                    if(f[l][i].g==0) continue;
                    auto nw=st.lower_bound(Node{f[l][i].f,f[l][i].g});
                    Node t={nw->val,nw->sum-f[l][i].g};
                    st.erase(nw);
                    if(t.sum!=0) st.insert(t);
                }
                ll=ls;
                if(!st.empty()){
                    auto p=st.begin();
                    f[l][r]={p->val+1,p->sum};
                    auto nw=st.lower_bound(Node{f[l][r].f,f[l][r].g});
                    long long tmp=0;
                    if(nw!=st.end()&&nw->val==f[l][r].f) tmp=nw->sum,st.erase(nw);
                    st.insert(Node{f[l][r].f,f[l][r].g+tmp});
                }
                // cout<<l<<" "<<r<<" "<<f[l][r].f<<" "<<f[l][r].g<<endl;
                if(f[l][r].g==2) ans++;
                if(!f[l][r].g) break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}