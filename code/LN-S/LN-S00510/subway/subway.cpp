#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
//queue<int>line[100002];
int ti[100020];//,mm[100002];
/*stack<int>bian[10000];
int g[10000][10002];
void shunxujiegou(int a,int total){
    while(mm[bian[a].top()]){
        bian[a].pop();
    if(bian[a].empty())return;
    }
    int q=bian[a].top();
    for(int i=0;i<line[q].size();i++){
        g[a][line[q].front()]=0;
        shunxujiegou(q,total);
        line[q].pop();
    }
    for(int i=0;i<m;i++){
            g[a][i]=min(g[a][i],ti[a]);
            shunxujiegou(i,total+ti[a]);
        }
    }
void floyd(){
for(int i=0;i<n;i++)
for(int j=0;j<i;j++){
    for(int k=0;k<n;k++){
        if(g[i][k]+g[k][j]<g[i][j])g[i][j]=g[i][k]+g[k][j];
    }
}
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //memset(g,0x7f,sizeof g);
    cin>>c>>n>>m>>d>>q;
    int w[m+1];
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
    int k;
        cin>>k;
            int a[k+2][k+3];
        for(int j=0;j<k;j++){
            cin>>a[i][j]>>ti[j];
      //      line[i].push(a[i][j]);
        //    bian[a[i][j]].push(i);
        }
    }
    //shunxujiegou(0,0);
    //floyd();
    while(q--){
        int st,sp;
        cin>>st>>sp;
        cout<<w[st]+w[sp];
        cout<<endl;
    }
    return 0;
}
