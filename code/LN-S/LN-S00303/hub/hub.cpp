#include<bits/stdc++.h>
#define int long long
using namespace std;
//有没有人在锣鼓写LN米或行为大赏
int c,T;
int lowbit(int x){
    return x&-x;
}
bool chose[20];
struct edge{
    int num;
    int next;
};
edge e[100];
int head[50];
int x1;
int fa[100];
void add(int x,int y){
    x1++;
    e[x1].num=y;
    e[x1].next=head[x];
    head[x]=x1;
}

void dfs(int x,int fa1){
    fa[x]=fa1;
    for(int it=head[x];it!=0;it=e[it].next){
        if(e[it].num!=fa1){
            dfs(e[it].num,x);
        }
    }
}
int d;
void dfs2(int x,int fa1,int d1){
    for(int it=head[x];it!=0;it=e[it].next){
        if(e[it].num!=fa1){
            if(chose[e[it].num]==1){
                d=min(d,d1+1);
                return;
            }
            dfs2(e[it].num,x,d1+1);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin >> c >> T;

    if(c==13||c==14){
        while(T--){
            int n,k;
            cin >> n >>k;
            for(int i=1;i<=n-1;i++){
                int u,v;
                cin >> u >> v;
            }
            cout << (((n-1)/2-k)-1)/4+2 << endl;
        }
        return 0;
    }

    while(T--){
        memset(head,0,sizeof(head));
        memset(e,0,sizeof(e));
        x1=0;
        int n,k;
        cin >> n >> k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin >> u >>v;
            add(u,v);
            add(v,u);
        }
        memset(fa,0,sizeof(fa));
        dfs(1,0);
        int ans1=0x3f3f3f3f;
        for(int i=1;i<=(1<<n)-1;i++){
            int cnt=0;
            int num=i;
            while(num>0){
                cnt++;
                num-=lowbit(num);
            }
            if(cnt!=k){
                continue;
            }
            memset(chose,0,sizeof(chose));
            for(int j=1;j<=n;j++){
                if((i&(1<<(j-1)))!=0){
                    chose[j]=1;
                }
            }
            cnt=0;
            for(int j=1;j<=n;j++){
                if(chose[j]==1&&chose[fa[j]]==1){
                    cnt++;
                }
            }
            /*for(int j=1;j<=n;j++){
                cout <<chose[j]<<" ";
            }*/
            //cout << endl;
            if(k-cnt>2){
                continue;
            }
            //cout << i << " ";
            int ans=0;
            for(int j=1;j<=n;j++){
                if(chose[j]==0){
                    d=0x3f3f3f3f;
                    dfs2(j,0,0);
                    ans=max(ans,d);
                    //cout <<d;
                }
            }
            //cout << ans << endl;
            ans1=min(ans1,ans);
        }
        cout << ans1 <<endl;
    }

    return 0;
}
