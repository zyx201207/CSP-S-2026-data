#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10005],place[10005];
vector<int>v;
bool vis[10005]={false};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[arr[j]]==true){
                while(v[v.size()-1]!=arr[j]){
                    vis[v[v.size()-1]]=false;
                    v.pop_back();
                }
                v.pop_back();
            }
            v.push_back(arr[j]);
            for(int k=0;k<v.size();k++){
                vis[v[k]]=true;
            }
        }
        for(int k=1;k<=m;k++){
            if(vis[k])
                place[k]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<place[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
