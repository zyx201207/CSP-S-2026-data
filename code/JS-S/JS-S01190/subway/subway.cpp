#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qd;
//time, v;
//per station, push the
int c,n,m,d,q,k;
int main(){
    cin >> c >> n >> m >> d >> q;
    int sation[m+1];
    for(int i=1;i<=m;i++){
        cin >> sation[i];
    }
    int next[n][m+1];
    int pre[n][m+1];
    int valuea[n][m+1];
    int dist[m+1]={0x3f3f3f3f};
    int a1,t1,a2,t2;
    int tem=0;
    bool first=true;
    queue<int> a;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            next[i][j]=pre[i][j]=valuea[i][j]=0;
        }
    }
    for(int p=0;p<n;p++){
        cin >> k;
        for(int i=1;i<=2*k;i++){
            cin>>tem;
            a.push(tem);
        }
        while(!a.empty()){
            a1=a.front();
            a.pop();
            t1=a.front();
            a.pop();
            if(!first){
                next[p][a2]=a1;
                pre[p][a1]=a2;
                valuea[p][a2]=t2;
            }
            if(a.empty()){
                next[p][a2]=a1;
                pre[p][a1]=a2;
                valuea[p][a2]=t2;
                break;
            }
            a2=a.front();
            a.pop();
            t2=a.front();
            a.pop();
            next[p][a1]=a2;
            pre[p][a2]=a1;
            valuea[p][a1]=t1;
            valuea[p][a2]=t2;
            first=false;
        }
    }
    int x,y;
    while(q--){
        cin >> x >> y;
        for(int i=0;i<=p;i++){
            if(next[i][x]!=0 && sation[x]+value[i][x] < dist[next[i][x]){
                pq.push({sation[x]+value[i][x],next[i][x]});
            }
        }
        while(!pq.empty()){
            auto[d,v]=pq.top();
            pq.pop();

            for(v=next[j][v])
        }
    }
}
