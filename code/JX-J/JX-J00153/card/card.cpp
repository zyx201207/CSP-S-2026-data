#include<bits/stdc++.h>
using namespace std;
const int N=500050,M=300050;
int n,m,a[N],sum[N],nxt[N];
map<int,int> ans;
vector<int> v[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int l=v[i].size();
        if(!l) continue;
        for(int j=0;j<l-1;j++){
            nxt[v[i][j]]=v[i][l-1];
        }
    }
    for(int i=n;i>0;i--){
        int j=i;
        while(j<=n){
            while(nxt[j]) j=nxt[j];
            sum[a[j]]++;
            j++;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",sum[i]);
    return 0;
}
