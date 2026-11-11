#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[15];
int n;
int d(int v,int l){
    int ans=10;
    if(b[v]){
        return l;
    }
    for(int i=1;i<=n;i++){
        if(a[i][v]){
            a[i][v]=0;
            a[v][i]=0;
            ans=min(ans,d(i,l+1));
            a[i][v]=1;
            a[v][i]=1;
        }
    }
    return ans;
}
int f(int l){
    int fin=100;
    if(l==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,d(i,0));
        }
        fin=min(fin,ans);
    return fin;
    }
for(int i=1;i<=n;i++){
    b[i]=1;
    fin=min(fin,f(l-1));
    b[i]=0;
}
return fin;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
    int k,x2,x1;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>x1>>x2;
        a[x1][x2]=1;
        a[x2][x1]=1;
    }
   cout<<f(k)<<endl;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        a[i][j]=0;
    }
   }
    }
    return 0;
}
