#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500009];
int c[300009];
bool vis[500009];
void fun(int start,int enda){
    for(int i=1;i<=enda;i++){
        vis[i]=true;
    }
    for(int i=start;i<=enda;i++){
        for(int j=start;j<i;j++){
            if(a[j]==a[i]){
                for(int k=j;k<i;k++){
                    vis[k]=false;
                    continue;
                }
            }
        }
    }
    //cout<<start<<endl;
    for(int i=start;i<=enda;i++){
        if(vis[i]==true){
            c[a[i]]++;
            //for(int j=start;j<=enda;j++){
            //    cout<<vis[j];
            //}
            //cout<<endl;
            //cout<<a[i]<<" "<<c[a[i]]<<endl;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        fun(i,n);
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
