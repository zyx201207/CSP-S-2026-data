#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int c[500010];
        for(int j=1;j<=n;j++){
            c[j]=a[j];
        }
        for(int j=1;j<i;j++){
            c[j]=0;
        }
        for(int j=1;j<=n;j++){
            if(c[i]==c[j]&&c[i]!=0){
                for(int k=i;k<j;k++){
                    c[k]=0;
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(c[j]!=0) b[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
