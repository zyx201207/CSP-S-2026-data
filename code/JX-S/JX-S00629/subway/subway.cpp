#include<bits/stdc++.h>
using namespace std;
struct node{
    long long id,num;
};
long long c,n,m,d,q;
long long points,ans[5000005],w[500005],a[500005],t[500005];
bool tag[5000005];
vector<node>v[5000005];
long long dfs(long long cn,long long fa,long long gol,long long cnt){
    if(cn==gol)return cnt;
    long long len=v[cn].size(),ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<len;i++){
        if(v[cn][i].id==fa||tag[v[cn][i].id])continue;
        tag[v[cn][i].id]=1;
        ans=min(ans,dfs(v[cn][i].id,cn,gol,cnt+v[cn][i].num));
        tag[v[cn][i].id]=0;
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    points=m;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        long long k,x,y;
        cin>>k;
        for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
        points++;
        for(int j=1;j<k;j++){
            v[points].push_back({++points,0});//bian
            v[points].push_back({points-1,0});//bian
            if(j==1){
                v[a[j]].push_back({points-1,t[j]});//zhantai
                v[points-1].push_back({a[j],t[j]});
            }
            v[a[j+1]].push_back({points,t[j+1]});//zhantai
            v[points].push_back({a[j+1],t[j+1]});
            //cout<<points-1<<' '<<points<<' '<<a[j]<<' '<<a[j+1]<<endl;
            //cout<<v[points-1].size()<<' '<<v[points].size()<<' '<<v[a[j]].size()<<' '<<v[a[j+1]].size()<<endl;
        }
    }
    //for(int i=1;i<=points;i++){
    //    cout<<i<<endl;
    //    long long len=v[i].size();
    //    for(int j=0;j<len;j++)cout<<v[i][j].id<<' '<<v[i][j].num<<endl;
    //}
    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        cout<<dfs(x,-1,y,0)+w[x]+w[y]<<endl;
    }

    return 0;
}
/*
0 1 3 20 1
1 2 3
3 1 4 2 5 3 6
1 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
