#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<vector<int>> dis(m+1,vector<int>(m+1,1e9));
    vector<vector<int>> cline(m+1,vector<int>());
    vector<vector<int>> tran(n+1,vector<int>());
    vector<vector<int>> ol(n+1,vector<int>());
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<int> tim(k+1);
        ol[i]=vector<int>(k+1);
        for(int j=1;j<=k;j++){
            cin>>ol[i][j];
            cin>>tim[j];
            cline[ol[i][j]].push_back(i);
            if(cline[ol[i][j]].size()>=2){
                //cout<<ol[i][j]<<endl;
                for(int l:cline[j]){
                     tran[l].push_back(ol[i][j]);
                }
            }
        }
        for(int j=1;j<=k;j++){
            dis[ol[i][j]][ol[i][j]]=0;
            for(int k=j+1;j<=k;j++){
                dis[ol[i][j]][ol[i][k]]=dis[ol[i][k]][ol[i][j]]=min(dis[ol[i][j]][ol[i][k]],tim[j]+tim[k]);
            }
        }
    }
    for(int l=1;l<=n;l++){
        for(int k=0;k<tran[l].size();k++){
            for(int i=1;i<ol[l].size();i++){
                //cout<<cline[2].size()<<endl;
                //cout<<
                for(int oth=0;oth<cline[tran[l][k]].size();oth++){
                    //cout<<11111<<endl;
                    if(cline[tran[l][k]][oth]==l) continue;
                    int l2=cline[tran[l][k]][oth];
                    for(int j=1;j<ol[l2].size();j++){
                        //cout<<tran[l][k]<<endl;
                        //cout<<22222<<endl;
                        int s1=ol[l][i];
                        int s2=ol[l2][j];
                        int tsf=tran[l][k];
                        cout<<s1<<" "<<s2<<" "<<tsf<<endl;
                        dis[s1][s2]=dis[s2][s1]=min(dis[s1][s2],dis[s1][tsf]+dis[tsf][s2]);
                        //cout<<dis[s1][tran[l][k]]<<" "<<dis[s1][];
                    }
                }
            }
        }
    }
    //cout<<dis[1][2]<<" "<<dis[2][3]<<endl;
    //cout<<dis[1][3]<<endl;
    //cout<<dis[2][6]<<endl;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<endl;

    }
}
