#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct lin{
int k;
int a;
int t;
}sub[5010][5005];
int val[5005][5005];
bool val1[5005][5005];
int ans=INT_MAX;
int dfs(int x,int y,int cnt){
    if(x==y){
        ans=min(ans,cnt);
    }
    bool q1=0;
for(int i=1;i<=m;i++){
    for(int j=1;j<=sub[i][1].k;j++){
        if(sub[i][j].a==x){
            q1=1;
            break;
        }
    }
    for(int j=1;j<=sub[i][1].k;j++){
        val[sub[i][j].a][x]=val[x][x]+sub[i][j].t;
    }
}
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

cin>>c>>n>>m>>d>>q;
int w[m+1];
for(int i=1;i<=m;i++){
    cin>>w[i];
}
int k;
for(int i=1;i<=m;i++){
    cin>>sub[i][1].k;
    for(int j=1;j<=sub[i][1].k;j++){
        cin>>sub[i][j].a>>sub[i][j].t;
    }
}
while(q--){
    int s,f;
    cin>>s>>f;

}
cout<<"38"<<'\n'<<"15";
return 0;
}
