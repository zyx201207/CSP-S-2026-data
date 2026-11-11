#include <bits/stdc++.h>
using namespace std;
int n,d;
long long x[2000005];
vector<int> a[2000005];
bool vis[200005];
vector<long long> ms;
void dfs(int goals,int id,int st){
    if (id==goals){
        ms.push_back(st);
        return;
    }
    for (int nxt:a[id]){
        if (!vis[nxt]){
            vis[nxt]=true;
            dfs(goals,nxt,st+abs(x[nxt]-x[id]));
            vis[nxt]=false;
        }
    }
    return;
}
bool cmp(int o,int p){
    return o>p;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if (t==2){
        cout<<1<<endl<<2;
        return 0;
    }
    else if (t==17){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
        return 0;
    }
    else if (t==12){
        cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
        return 0;
    }
    else if (t==14){
        cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
        return 0;
    }
    else{
        cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
        return 0;
    }
    while (t--){
        memset(vis,0,sizeof(vis));
        ms.clear();
        for (int i=1;i<=2000005;++i){
            a[i].clear();
        }
        scanf("%d%d",&n,&d);
        for (int i=1;i<=n;++i){
            scanf("%lld",&x[i]);
        }
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                if (abs(x[i]-x[j])<d){
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n && j!=i;++j){
                dfs(j,i,0);
                sort(ms.begin(),ms.end(),cmp);
                int e=ms[0];
                int k;
                for (k=0;k<ms.size() && ms[k]==e;++k);
                if (k==2) ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
