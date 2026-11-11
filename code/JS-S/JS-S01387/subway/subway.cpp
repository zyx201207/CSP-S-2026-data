#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> stat[600010];
long long vp[500005][505];
long long op[505][505];
long long v[600010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d ",&v[i]);
    }
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        for(int j=1;j<=tmp;j++){
            int tmp1,tmp2;
            scanf("%d %d",&tmp1,&tmp2);
            stat[tmp1].push_back({i,tmp2});
            vp[tmp1][i]=tmp2;
 //           cout<<i<<" "<<tmp1<<" "<<tmp2<<endl;
        }
    }
    memset(op,0x1f,sizeof(op));
    for(int i=1;i<=m;i++){
        for(pair<int,long long> j:stat[i]){
            for(pair<int,long long> k:stat[i]){
                if(j.first>=k.first){
                    continue;
                }
                if(!op[j.first][k.first]){
                    op[j.first][k.first]=j.second+k.second;
                }
                else{
                    op[j.first][k.first]=min(j.second+k.second,op[j.first][k.first]);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j){
                    op[i][j]=0;
                }
                op[i][j]=min(op[i][j],op[i][k]+op[k][j]);
            }
        }
    }
//    for(int i=1;i<=n;i++){
//       for(int j=1;j<=n;j++){
//           cout<<op[i][j]<<" ";
//       }
//       cout<<endl;
//    }
    while(q--){
        int s,e;
        cin>>s>>e;
        long long ans=(long long)(pow(2,60));
        for(pair<int,long long> i:stat[s]){
            for(pair<int,long long> j:stat[e]){
                pair<int,long long> itmp=i,jtmp=j;
                if(itmp.first>jtmp.first){
                    swap(itmp,jtmp);
                }
                ans=min(ans,v[s]+vp[s][i.first]+v[e]+vp[e][j.first]+op[itmp.first][jtmp.first]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
