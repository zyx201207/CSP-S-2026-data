#include<bits/stdc++.h>
using namespace std;
struct sw{
    int nofs;
    pair<int,int> sts[550];
};
struct st{
    int nogt=0;
    int gt[550];
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int io[100010];
    for(int i=0;i<m;i++){
        cin>>io[i];
    }
    sw subways[510];
    st stations[510];
    for(int i=0;i<n;i++){
        cin>>subways[i].nofs;
        for(int j=0;j<subways[i].nofs;j++){
            cin>>subways[i].sts[j].first>>subways[i].sts[j].second;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<subways[i].nofs-1;j++){
            stations[subways[i].sts[j].first].gt[subways[i].sts[j+1].first]=subways[i].sts[j].second+subways[i].sts[j+1].second;
            stations[subways[i].sts[j].first].nogt++;
            stations[subways[i].sts[j+1].first].nogt++;
            stations[subways[i].sts[j+1].first].gt[subways[i].sts[j].first]=subways[i].sts[j+1].second+subways[i].sts[j].second;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<stations[i].nogt;j++){
            for(int k=0;k<stations[j].nogt;k++){
                stations[i].gt[k]=min(stations[i].gt[k],stations[i].gt[j]+stations[j].gt[k]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int b,e;
        cin>>b>>e;
        cout<<io[b]+io[e]+stations[b].gt[e];
    }
    return 0;
}
