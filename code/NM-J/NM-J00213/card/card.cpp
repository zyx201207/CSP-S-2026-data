#include<bits/stdc++.h>
using namespace std;
int a[100000];
int c[10000]{0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b[10000]{0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=1;
    }
    int x=m-1;
    while(x!=0){
        for(int i=1;i<=x;i++){
            if(b[a[i]]==1){
                int b[10000]{0};
                b[a[i]]=1;
            }
            else{
                b[a[i]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]==1){
                c[j]++;
            }
        }
        x--;
    }
    for(int l=1;l<=m;l++){
        cout<<c[l]<<" ";
    }
    return 0;
}
