#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//lines,stations,most lines in one station,plans
int w[500005];//enter exit time
struct node{
    int k;//stations
    int a[500005],t[500005];//station number,time
    int tmp[500005];
}line[505];
struct station{
    int op;
    int u[25],v[25];
}stat[500005];
int f(int x,int y,int l){
    queue<int>q;
    q.push(x);
    int res[500005];
    memset(res,0,sizeof(res));
    int last=l;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=1;i<=stat[p].op;i++){
            int zuo=line[stat[p].v[i]].a[line[stat[p].v[i]].tmp[p]-1],you=line[stat[p].v[i]].a[line[stat[p].v[i]].tmp[p]+1];
            if(line[stat[p].v[i]].tmp[p]==1)zuo=1;
            if(line[stat[p].v[i]].tmp[p]==line[stat[p].v[i]].k)you=line[stat[p].v[i]].k;
            if(stat[p].v[i]==l){
                if(res[zuo]>res[p]){
                    q.push(zuo);
                    res[zuo]=res[p];
                    last=stat[p].v[i];
                }
                if(res[you]>res[p]){
                    q.push(you);
                    res[you]=res[p];
                    last=stat[p].v[i];
                }
            }else{
                if(res[zuo]>res[p]+stat[p].u[stat[p].v[i]]+stat[p].u[l]){
                    q.push(zuo);
                    res[zuo]=res[p]+stat[p].u[stat[p].v[i]]+stat[p].u[l];
                    last=stat[p].v[i];
                }
                if(res[you]>res[p]+stat[p].u[stat[p].v[i]]+stat[p].u[l]){
                    q.push(zuo);
                    res[you]=res[p]+stat[p].u[stat[p].v[i]]+stat[p].u[l];
                    last=stat[p].v[i];
                }
            }
        }
    }
    return res[y]+stat[y].u[last];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>line[i].k;
        for(int j=1;j<=line[i].k;j++){
            cin>>line[i].a[j]>>line[i].t[j];
            line[i].tmp[line[i].a[j]]=j;
            stat[line[i].a[j]].op++;
            stat[line[i].a[j]].u[stat[line[i].a[j]].op]=i;
            stat[line[i].a[j]].v[stat[line[i].a[j]].op]=line[i].t[j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=0x3f3f3f3f;
        for(int i=1;i<=stat[x].op;i++){
            ans=min(ans,f(x,y,stat[x].u[i]));
        }cout<<ans+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
