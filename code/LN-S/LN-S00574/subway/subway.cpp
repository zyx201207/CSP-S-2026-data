#include <bits/stdc++.h>
using namespace std;
int c,m,n,d,q,w[500000],k[500000];
vector<vector<int> >a,t;
vector<vector<pair<short,int> > >b;
int ltlt[500][500],a1[500][500];
void f(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                if(ltlt[j][i]+ltlt[i][k]<ltlt[j][k]){
                    ltlt[j][k]=ltlt[j][i]+ltlt[i][k];
                    ltlt[k][j]=ltlt[j][i]+ltlt[i][k];
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    b.push_back(vector<pair<short,int> >());
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
        b.push_back(vector<pair<short,int> >());
    }
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            if(i!=j)
            ltlt[i][j]=1<<29;
            a1[i][j]=1<<29;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",&k[i]);
        a.push_back(vector<int>());
        t.push_back(vector<int>());
        for(int j=0;j<k[i];j++){
            a[i].push_back(0);
            t[i].push_back(0);
            scanf("%d%d",&a[i][j],&t[i][j]);
            for(pair<short,int> s:b[a[i][j]]){
                if(a1[i][s.first]>t[i][j]+s.second){
                    a1[i][s.first]=t[i][j]+s.second;
                    ltlt[i][s.first]=a1[i][s.first];
                    a1[s.first][i]=t[i][j]+s.second;
                    ltlt[s.first][i]=a1[s.first][i];
                }
            }
            b[a[i][j]].push_back({i,t[i][j]});
        }
    }
    f();
    for(int i=0;i<q;i++){
        int ans=1<<30;
        int s,t;
        scanf("%d%d",&s,&t);
        for(pair<short,int> j:b[s]){
            for(pair<short,int> k:b[t]){
                ans=min(ans,w[s]+w[t]+ltlt[j.first][k.first]+j.second+k.second);
            }
        }
        printf("%d ",ans);
    }
    for(;;);
    return 0;
}
