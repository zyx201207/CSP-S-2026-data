#include<bits/stdc++.h>
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
using namespace std;
int main(){
    long long p[100000];
    long long zm[100000][100000];
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            zm[i][j]=p[j];
            for(int k=j-1;k>=1;k--){
                if(zm[i][k]==p[j]){
                    for(int l=1;l<=k;j++){
                        zm[i][l]==zm[i][k-1+l];
                    }
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        int a=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(zm[i][j]==k) a++;
            }
        }
        cout<<k<<' ';
    }
    return 0;
}
