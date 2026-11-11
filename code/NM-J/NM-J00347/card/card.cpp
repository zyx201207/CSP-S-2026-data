#include <bits/stdc++.h>
using namespace std;
int n,m,a[500099],x[300099],b[500099],vis[300099][2];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int h=0;h<n;h++){
        for(int i=h;i<n;i++){
            vis[a[i]][0]++;
            if(vis[a[i]][0]==2){
                for(int j=vis[a[i]][1];j<i;j++){
                    vis[a[j]][0]--;
                    vis[a[j]][1]=0;
                }
            }
            vis[a[i]][1]=i;
        }
        for(int i=0;i<m;i++){
            if(vis[i][0]>0){
                x[i]++;
            }
        }
        for(int i=0;i<m;i++){
            vis[i][0]=0;
            vis[i][1]=0;
        }
    }
    for(int i=0;i<m;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
