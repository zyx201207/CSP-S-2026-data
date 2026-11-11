#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int xx,y;
int w[500005];
struct node{
    int k;
    vector<int> a,t;
}x[505];
bool v[500005];
long long minn=1e18+5;
void dfs(int now,long long ans,int sub){
    if(now==y){
        minn=min(ans,minn);
        return;
    }
    if(ans>minn)
        return;
    for(int i=1;i<=m;i++){
        if(!v[i]){
            v[i]=1;
            for(int j=0;j<x[i].a.size();j++){
                if(sub==x[i].a[j])
                    dfs(i,ans+x[now].t[j],sub);
                else
                    dfs(i,ans+x[now].t[j]+x[i].t[j],x[i].a[j]);
            }
            v[i]=0;
        }
    }

}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>x[i].k;
        for(int j=1;j<=x[i].k;j++){
            int a,t;
            cin>>a>>t;
            x[a].a.push_back(i);
            x[a].t.push_back(t);
        }
    }
    while(q--){
        cin>>xx>>y;
        minn=1e18+5;
        dfs(xx,0,0);
        cout<<minn+w[xx]+w[y]<<endl;
    }
    return 0;
}
