#include <bits/stdc++.h>
using namespace std;
int n,m,p=0;
int a[350000];
int cnt[350000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x[10000];
        bool b[10000];
        for(int j=i;j<=n;j++){
            //int g=0;
            if(b[a[j]]==1){
                for(int k=x[a[j]];k<=j;k++){
                    b[a[k]]=0;
                }
                //g=1;
            }
            b[a[j]]=1;
            x[a[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(b[j]==1)cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
