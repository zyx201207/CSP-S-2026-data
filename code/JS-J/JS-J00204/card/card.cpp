#include<bits/stdc++.h>
using namespace std;
queue<int> k;
int ans[300010];
int n,m;
int a[300010];
int vis[300010];
int l=0;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){

    //cout<<"k";
    //for(int j=1;j<=m;j++){
      //  cout<<vis[i]<<' ';
    //}
    for(int j=i;j<=n;j++){
        int cnt=0;
        k.push(a[j]);
        l++;
        if(vis[a[j]]!=0){
                k.pop();
                l--;
                while(k.front()!=a[j]&&k.empty()==0){
                    k.pop();
                    l--;
                }
            }
        else{
            vis[a[j]]=j;
        }
    }
    for(int j=0;j<l;j++){
        //cout<<k.front();
        ans[k.front()]++;
        k.pop();
    }
    for(int j=0;j<=m;j++){
        vis[j]=0;
    }
    l=0;
    //cout<<endl;
}
for(int i=1;i<=m;i++){
    cout<<ans[i]<<' ';
}
return 0;
}
