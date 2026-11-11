#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    int a[m];
    bool b[n+1];
    for(int i=1;i<=n+1;i++){
        b[i]=0;
    }
    int c[n+1];
    int d[n+1][2];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        if(d[a[i]][0]==0)d[a[i]][0]=i;
    }
    for(int i=m-1;i<=0;i--){
        if(d[a[i]][1]==0)d[a[i]][1]=i;
    }
    c[a[m-1]]=m;
    b[a[m+1]]=1;
    for(int i=m-1;i>=1;i--){
       if(d[a[i]][]
    }
    return 0;
}

