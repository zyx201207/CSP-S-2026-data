#include<bits/stdc++.h>
using namespace std;
int n,m,a[300050],res[300050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        vector<int> q;
        for(int j=i-1;j<=n;j++){
            for(auto k:q){
                if(k==a[j]){
                    while(q.back()!=k&&!q.empty())q.pop_back();
                    q.pop_back();
                }
            }
            q.push_back(a[j]);
        }
        bool temp[300050];
        memset(temp,0,sizeof temp);
        for(auto k:q){
            temp[k]=1;
        }
        for(int i=1;i<=m;++i)if(temp[i])++res[i];
    }
    for(int i=1;i<=m;++i)printf("%d ",res[i]);
    return 0;
}
