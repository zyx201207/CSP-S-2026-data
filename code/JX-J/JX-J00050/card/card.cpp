#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005];

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i+=i){
        if(a[i]==1) continue;
        if(a[i]==a[i+1]){
            b[i]=1;
            b[i+1]=1;
        }
    }
    int h=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            h=0;
            if(a[j]=i && b[j]==0){
                h++;
            }
        }
        cout<<h<<' ';
    }
}
