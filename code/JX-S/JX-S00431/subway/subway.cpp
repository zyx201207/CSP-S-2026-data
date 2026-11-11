#include<bits/stdc++.h>
using namespace std;
//Good luck
//FU CCF
//It's toooooooo difficult
//10 years OI empty
const int maxm=5e5+5;
const int maxn=505;
int c,n,m,d,q;
int w[maxm];
int k;
int t[maxm][maxn]={0};
int x,y;
vector<int> e[maxm];
int vim[maxm]={0};
vector<int> xian[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            t[a][i]=b+w[a];
            vim[a]++;
            e[a].push_back(b);
            e[b].push_back(a);
            //xian[a].push_back(i);
            //xian[b].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(d==1){
            cout<<t[x][1]+t[y][1]<<"\n";
            continue;
        }
    }
    return 0;
}
