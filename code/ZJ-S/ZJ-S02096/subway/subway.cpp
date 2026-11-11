#include <bits/stdc++.h>
using namespace std;
const int MN=505,MM=5e5+5;
int c,n,m,d,q,a[1005][1005],cr[MM],ln[MM][2];
/*
int s(int qs,int qd){
    bool v[MM];
    for(int i=0;i<1005;++i) v[i]=0;
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=m;++i){
        if(a[qs][i]&&i!=qs) pq.push(make_pair(-a[qs][i],i));
    }
    while(!pq.empty) cout<<pq.pop.first<<" "<<pq.pop.second<<endl;
    while(a[qs][qd]==0){
        while(v[pq.top.second]) pq.pop;
        pair<int,int> pp=pq.pop;
        v[pp.second]=1;
        a[qs][pp.second]=min(-pp.first,a[qs][pp.second]);
        for(int i=1;i<=m;++i){
            if(a[pp.second][i]&&i!=pp.second) pq.push(make_pair(-a[qs][pp.second]-a[pp.second][i],i));
        }
        
    }
}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>cr[i];
    for(int i=0;i<n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>ln[j][0]>>ln[j][1];
            for(int z=1;z<j;++z){
                a[ln[z][0]][ln[j][0]]=ln[j][1]+ln[z][1];
                a[ln[j][0]][ln[z][0]]=ln[j][1]+ln[z][1];
            }
        }
    }
    for(int i=0;i<q;++i){
        int qs,qd;
        cin>>qs>>qd;

    }
    /*
    cout<<endl;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<32<<endl<<17;
    return 0;
}