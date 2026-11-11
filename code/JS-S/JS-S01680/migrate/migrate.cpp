#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    long long x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+int(ch-'0');
        ch=getchar();
    }
    x*=f;
    return x;
}
long long n,d;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c=read(),t=read();
    while(t--){
        map<pair<int,int>,pair<int,int> >vis;
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    vis[{i,j}].first=1;
                    vis[{i,j}].second=1;
                }
                else{
                    vis[{i,j}].first=n-1;
                    vis[{i,j}].second=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<=j-1;k++){
                    if(vis[{i,j}].first<vis[{i,k}].first+vis[{k,j}].first) continue;
                    if(vis[{i,k}].first+vis[{k,j}].first<vis[{i,j}].first){
                        vis[{i,j}].first=vis[{i,k}].first+vis[{k,j}].first;
                        vis[{i,j}].second=1;
                    }else vis[{i,j}].second++;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(vis[{i,j}].second==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
