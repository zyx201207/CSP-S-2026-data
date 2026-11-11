#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500003]={},sb[500003]={},vis[500003]={},rec[500003]={},c=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        c=1;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=c;
                sb[c]=a[j];
                c++;
            }else{
                c=vis[a[j]];
                for(int k=vis[a[j]];k<=n;k++){
                    vis[sb[k]]=0;
                    sb[k]=0;
                }
                sb[c]=a[j];
                vis[a[j]]=c;
                c++;
            }
        }
        /*for(int j=1;j<=n;j++){
            cout<<sb[j]<<' ';
        }cout<<endl;*/
        for(int j=1;j<=n;j++){
            rec[sb[j]]+=1;
        }
        for(int j=1;j<=n;j++){
            sb[j]=0;vis[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<rec[i]<<' ';
    }
}
