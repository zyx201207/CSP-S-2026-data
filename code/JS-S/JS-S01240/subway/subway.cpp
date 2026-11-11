#include<bits/stdc++.h>
using namespace std;
int st[500005],G[505][505];
int y,n;
bool f[505];
struct lines{
    int num,sta[500005],tim[500005];
}s[505];
void time_(int a,int b){
    for(int i=1;i<=s[a].num;i++){
        for(int j=1;j<=s[b].num;j++){
            if(s[a].sta[i]==s[b].sta[j]){
                G[a][b] = min(G[a][b],s[a].tim[i]+s[b].tim[j]);
                G[b][a] = G[a][b];
            }
        }
    }
    return;
}
int judgeline_(int l){
    for(int i=1;i<=s[l].num;i++){
        if(s[l].sta[i]==y){
            return s[l].tim[i];
        }
    }
    return 0;
}
int dfs(int l,int times){
    f[l] = true;
    int k = judgeline_(l);
    if(k!=0){
        return times+k;
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        if(G[l][i]!=INT_MAX&&!f[i]){
            ans = min(dfs(i,times+G[l][i]),ans);
        }
    }
    f[l] = false;
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            G[i][j] = INT_MAX;
            G[j][i] = INT_MAX;
        }
    }
    int c,m,d,q,x,ans = INT_MAX;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>st[i];
    }
    for(int i=1;i<=n;i++){
        cin>>s[i].num;
        for(int j=1;j<=s[i].num;j++){
            cin>>s[i].sta[j]>>s[i].tim[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            time_(i,j);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans = INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s[i].num;j++){
                if(s[i].sta[j]==x){
                    for(int i=1;i<=505;i++){
                        f[i] = false;
                    }
                    ans = min(ans,dfs(i,s[i].tim[j]));
                }
            }
        }
        cout<<ans+st[x]+st[y]<<endl;
    }
    return 0;
}
