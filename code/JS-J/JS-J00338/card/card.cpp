#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[m],c[n],p[n],x,mu;
    bool f;
    for(int i=0;i<m;i++) a[i]=0;
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) p[j]=0;
        x=0;
        f=false;
        for(int j=i;j<n;j++){
            mu=0;
            for(int k=0;k<x;k++){
                if(p[k]==c[j]){
                    f=true;
                    mu=k;
                }
            }
            if(f){
                for(int k=mu;k<x;k++) p[k]=0;
                x=mu;
                p[x]=c[j];
                x++;
                f=false;
            }else{
                p[x]=c[j];
                x++;
            }
        }
        for(int j=0;j<x;j++){
            a[p[j]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
