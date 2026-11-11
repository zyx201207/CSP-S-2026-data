#include<bits/stdc++.h>
using namespace std;
long long _,n,m,x,y,_2,q2,k,w[1010101],a[1100][1010],t[510][511],z[510][510],t2[510][500100],zdl[1010][1010],st[1010][1010];
vector<long long>q[510110];
vector<long long>zx[510101];
long long d[510][510];
vector<pair<long long,long long>>tu[501010];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q3;
void ycl(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(z[i][j]!=1e18){
                tu[i].push_back(make_pair(j,z[i][j]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int k6=1;k6<=n;k6++){
            d[i][k6]=1e18;
        }
        d[i][i]=0;
        while(!q3.empty()){
            q3.pop();
        }
        q3.push(make_pair(0,i));
        for(int j=1;j<=n;j++){
            st[i][j]=0;
        }
        while(!q3.empty()){
            if(st[i][q3.top().second]==0){
                for(int j=0;j<tu[q3.top().second].size();j++){
                    if((q3.top().first+tu[q3.top().second][j].second)<d[i][tu[q3.top().second][j].first]){
                        d[i][tu[q3.top().second][j].first]=(q3.top().first+tu[q3.top().second][j].second);
                        q3.push(make_pair(d[i][tu[q3.top().second][j].first],tu[q3.top().second][j].first));
                    }
                }
                st[i][q3.top().second]=1;
            }
            q3.pop();
        }
        for(int j=1;j<=n;j++){
            zdl[i][j]=d[i][j];
        }
    }
}
long long qx(long long st,long long en){
    long long ans=1e18;
    for(int i=0;i<q[st].size();i++){
        for(int j=0;j<q[en].size();j++){
            if(q[st][i]==q[en][j]){
                return 0;
            }
            ans=min(zdl[q[st][i]][q[en][j]]+t2[q[st][j]][st]+t2[q[en][j]][en],ans);
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>_>>n>>m>>_2>>q2;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            t2[i][a[i][j]]=t[i][j];
            q[a[i][j]].push_back(i);
            zx[a[i][j]].push_back(t[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            z[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<q[i].size();j++){
            for(int k2=j+1;k2<q[i].size();k2++){
                z[q[i][j]][q[i][k2]]=min(z[q[i][j]][q[i][k2]],zx[i][j]+zx[i][k2]);
                z[q[i][k2]][q[i][j]]=z[q[i][j]][q[i][k2]];
            }
        }
    }
    ycl();
    for(int i=1;i<=q2;i++){
        cin>>x>>y;
        cout<<w[x]+w[y]+qx(x,y)<<"\n";
    }
    return 0;
}
