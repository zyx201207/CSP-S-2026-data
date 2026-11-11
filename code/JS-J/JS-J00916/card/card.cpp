#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N],b[N],top=0,last[N],ans[N];
map<int,int> vis;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

      for(int i = 1;i <= n;i++){
        vis.clear();
        top=0;
        for(int j = i;j <= n;j++){
            vis[a[j]]++;
            if(vis[a[j]]==2){
                for(int k = last[a[j]]+1;k < j;k++){
                    last[b[k]]=0;
                    vis[b[k]]=0;
                }
                vis[a[j]]--;
                top=last[a[j]];
            }
            else{
                b[++top]=a[j];
                last[a[j]]=top;
            }
        }
        for(int j = 1;j <= top;j++){
            ans[b[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}
