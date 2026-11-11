#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],key;
int ip[500005];
map <int,int> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];if(a[i]<a[i-1]) key=1;
        ip[a[i]]=i;
    }
    if(!key){
        for(int i=1;i<=m;i++){
            cout<<ip[a[i]]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!mp[a[j]]) mp[a[j]]=1;
            else {for(int o=j-1;o>=1;o--){if(a[o]!=a[j]) mp[a[o]]=0; else{ break; } }mp[a[j]]=1;}
        }
        for(int j=1;j<=m;j++){
            //cout<<mp[j]<<" ";
            if(mp[j]==1) b[j]++;
        }
        //cout<<"\n";
        mp.clear();
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}
