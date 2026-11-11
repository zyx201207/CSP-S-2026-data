#include<bits/stdc++.h>
using namespace std;
struct hyw{
    int bh,tim;
};
int w[500005],k[505];
vector<hyw> a1[505];
long long minx;
bool book[3][505];
void dfs(int dq,int mb,long long js,int uord){
    if(dq==mb&&uord==2){
        minx=min(js,minx);
        return;
    }
    book[uord][dq]=1;
    if(uord==2){
        if(book[0][dq]==0){
            dfs(dq,mb,js+w[dq],0);
        }
    }
    if(uord==0){
        if(book[3][dq]==0){
            dfs(dq,mb,js+a1[dq][dq].tim,3);
        }
        for(int i=0;i<a1[dq].size();i++){
            if(book[0][a1[dq][i].bh]==0){
                dfs(a1[dq][i].bh,mb,js+a1[dq][dq].tim+a1[dq][i].tim,1);
            }
        }
    }
    book[uord][dq]=0;
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m,c,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int al,tl;
            cin>>al>>tl;
            a1[i].push_back({al,tl});
        }
    }
    while(q--){
        int x,y;
        minx=1e12;
        cin>>x>>y;
        dfs(x,y,0,2);
        cout<<minx<<endl;
    }
    return 0;
}
