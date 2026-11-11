#include<bits/stdc++.h>
using namespace std;
int a[10000001],q[10000001],ans[10000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int node=0;
        for(int j=i;j<=n;j++){
            bool flag=0;
            int x;
            for(int k=1;k<=node;k++){
                if(a[j]==q[k]){
                    flag=1;
                    x=k;
                    break;
                }
            }
            if(flag==0){
                q[++node]=a[j];
            }else{
                node=x;
            }
        }
        for(int j=1;j<=node;j++){
            ans[q[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}