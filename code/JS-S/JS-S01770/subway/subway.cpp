#include<bits/stdc++.h>
using namespace std;
long long t[1000010];
long long b[1000010];
vector<int> edges[1000010];
int end2=0;
void dfs(int x,int deep){

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<i;j++){
                edges[b[i]].push_back(b[j]);
                edges[b[j]].push_back(b[i]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int start1,end1;
        scanf("%d%d",&start1,&end1);
        end2=end1;
        dfs(start1,0);
    }

}
