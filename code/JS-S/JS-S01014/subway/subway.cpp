#include<bits/stdc++.h>
using namespace std;
int n,m,s,e,x,y,z;//eage,dot,start,end,cin123
int c,d,qu;//fw,fw,question
int w[505];
int a1,a2,t,k;
int dis[505];
vector<pair<int,int> > Time[505];//line,t ting->tai
vector<pair<int,int> > v[500005];//to,worth
bool b[500005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > > q;
int ft(int ns,int nl,int ll){
    int ans=0;
    for(int i=0;i<Time[ns].size();i++){
        int sg=Time[ns][i].first,on=Time[ns][i].second;
        if(sg==nl)ans+=on;
        else if(sg==ll)ans+=on;
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&qu);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d%d",&a2,&t);
            Time[a2].push_back({i,t});
            if(j==0){
                a1=a2;
                continue;
            }
            v[a1].push_back({a2,i});
            a1=a2;
        }
    }

        for(int i=1;i<=m;i++){
            dis[i]=1e9;
        }
        for(int l=0;l<qu;l++){
            scanf("%d%d",&s,&t);
        int mi=1e9;
        for(int i=0;i<v[s].size();i++){
            q.push({0,{s,v[s][i].second}});//worth,dot,line
            memset(b,sizeof(b),0);
            dis[s]=0;
            while(!q.empty()){
                int kd=q.top().second.first;
                int kkd=q.top().second.second;
               // cout<<kd<<" "<<kkd<<endl;
                q.pop();
                if(b[kd]==1)continue;
                b[kd]=1;
                for(int i=0;i<v[kd].size();i++){
                    int ck=v[kd][i].first,dd=v[kd][i].second;
                    //station,line
                    if(dd==kkd){
                        if(dis[ck]>dis[kd]){
                            dis[ck]=dis[dd];
                             q.push({-dis[ck],{ck,dd}});
                        }
                    }else if(dis[ck]>dis[kd]+ft(kd,dd,kkd)){
                        dis[ck]=dis[kd]+ft(kd,dd,kkd);
                        q.push({-dis[ck],{ck,dd}});
                    }
                }
            }
            if(mi>dis[t])mi=dis[t];
        int ccf=ft(s,v[s][i].second,v[s][i].second);
        int ccf2=ft(s,v[t][i].second,v[t][i].second);
        cout<<mi+w[s]+w[t]+ccf+ccf2;
        }
        }
return 0;
}
