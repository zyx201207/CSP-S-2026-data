#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int a[10005][10005];
vector<int> asd[10001];
int anss;
void dfs(int ax,int ay,int ii,int jj,int bushu){
    for(int i=0;i<asd[ii].size();i++){
        if(asd[ii][i]==ay){
            anss=min(anss,bushu);
            return;
        }
    }
    for(int j=0;j<m;j++){
        for(int op=0;op<asd[ii].size();op++){
            for(int u=0;u<asd[j].size();op++){
                if(asd[ii][op]==asd[j][u]){
                    bushu+=2;
                    dfs(ax,ay,j,u,bushu);
                }
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    int p;
    for(int i=0;i<n;i++){
       int k,nam;
       cin>>k;
       cin>>nam>>p;
       asd[i].push_back(nam);
    }
    while(q--){
        anss=0;
        int ax,ay;
        cin>>ax>>ay;
        for(int i=0;i<m;i++){
            for(int j=0;j<asd[i].size();j++){
                if(asd[i][j]==ax){
                    dfs(ax,ay,i,j,0);
                }
            }
        }
        cout<<w[ax]+anss*p+w[ay]<<endl;
    }
    return 0;
}
