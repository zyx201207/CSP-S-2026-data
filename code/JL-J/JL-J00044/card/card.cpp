#include<bits/stdc++.h>
using namespace std;
int g[100005];
int n,m;
void afg(int c[100005],int d[100005],int e){
    for(int i=0+e;i<n;i++){
        d[i]=c[i];
        for(int j=0;j<i;j++){
            if(c[i]==d[j]){
                for(int z=j;z<i;z++){
                    d[z]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(d[i]==j){
                g[j]+=1;
                break;
            }
        }
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[100005],b[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        afg(a,b,i);
    }
    for(int i=0;i<m;i++){
        cout<<g[i]<<" ";
    }
    return 0;
}
