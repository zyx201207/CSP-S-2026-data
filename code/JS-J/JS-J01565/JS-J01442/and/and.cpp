#include<bits/stdc++.h>
#define N 200005
using namespace std;
int a[N],n,m,ans=INT_MAX;
bool f[N][32],vis[32],k[N],t[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        for(int j=0;x!=0;j++){
            f[i][31-j]=(x%2);
            x=x>>1;
        }
    }
    for(int i=0;i<32;i++){
        int cnt=0;
        for(int j=0;j<n;j++){cnt+=f[j][i];}
        if(cnt>=m){vis[i]=1;}
    }
    int i=0;
    for(;i<32;i++){
        if(vis[i]){
            for(int j=0;j<n;j++){k[j]=f[j][i];}
            break;
        }
    }
    for(;i<32;i++){
        if(vis[i]){
            int cnt=0;
            for(int j=0;j<n;j++){t[j]=k[j]&f[j][i];cnt+=t[j];}
            if(cnt<m){continue;}
            else{for(int j=0;j<N;j++){k[j]=t[j];}}
        }
    }
    int cnt=0;
    for(i=0;i<n;i++){
        if(k[i]){ans=ans&a[i];}
    }
    cout<<ans;
    return 0;
}
