#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int gt[555][555],w[500010];
struct egde{
    int num[500010];
}e[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(gt,0x3f,sizeof gt);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    vector<int>mm[m+1];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }for(int i=1;i<=n;i++){
        gt[i][i]=0;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int ak,bk;
            cin>>ak>>bk;
            e[i].num[ak]=bk;
            for(int k=0;k<mm[ak].size();k++){
                int cst=mm[ak][k];
                gt[cst][i]=min(e[i].num[ak]+e[cst].num[ak],gt[cst][i]);
                gt[i][cst]=gt[cst][i];
            }
            mm[ak].push_back(i);
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(gt[i][j]>gt[i][k]+gt[k][j])
                    gt[i][j]=gt[i][k]+gt[k][j];
    for(int i=1;i<=q;i++){
        int minn=INT_MAX;
        int s,t;
        cin>>s>>t;
        for(int jj=0;jj<mm[s].size();jj++){
            for(int kk=0;kk<mm[t].size();kk++){
                int j=mm[s][jj];
                int k=mm[t][kk];
                minn=min(gt[j][k]+e[j].num[s]+e[k].num[t],minn);
            }
        }
        cout<<w[s]+w[t]+minn<<'\n';
    }
    return 0;
}
