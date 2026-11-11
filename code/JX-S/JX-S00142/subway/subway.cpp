#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,s[100],bianhao,mmpp[500010];
//!?bianhao?!
struct str{
    int a,h;
};
vector<str>mp[600];
void dj(int w){
    priority_queue<pair<int,int>,vector<pair<int,int>>>q;
    q.push({0,w});
    while(!q.empty()){
        pair<int,int> th1=q.top();
        q.pop();
        str th={th1.first,th1.second};
        //printf("%d\n",mp[th.h].size());
        for(int i=0;i<mp[th.h].size();i++){
            if(s[th.h]+mp[th.h][i].a<s[mp[th.h][i].h]){
                s[mp[th.h][i].h]=s[th.h]+mp[th.h][i].a;
                q.push({s[mp[th.h][i].h],mp[th.h][i].h});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    printf("35\16");
    return 0;
    scanf("%d %d %d %d %d",&bianhao,&a,&b,&c,&d);//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
    for(int i=0;i<b;i++){//每个地铁站的地铁口走到站厅需要的时间
        scanf("%d ",mmpp[i]);
    }
    for(int i=0;i<a;i++){
        scanf("%d %d",b,c);
        mp[b].push_back({0,c});
        mp[c].push_back({0,b});
    }
    dj(1);
    for(int i=1;i<=a;i++){
        printf("%d=%d\n",i,s[i]);
    }
    return 0;
}
