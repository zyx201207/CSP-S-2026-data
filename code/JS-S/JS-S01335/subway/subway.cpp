#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=5e5+5;
int w[M];
long long dis[N][N];
vector<pair<int,int>>a[N];
vector<int>t[M];
vector<int>li[M];
int k[N];
vector<vector<int>>b;
int read(){
    int s=0,k=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*k;
}
void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<=9){
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    vector<int>tmp(n+5,0);
    for(int i=1;i<=m+5;i++)b.push_back(tmp);
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            int x,y;
            x=read(),y=read();
            t[x].push_back(y);
            li[x].push_back(i);
            a[i].push_back({x,t[x].size()-1});
            b[x][i]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e18;
            if(i==j)dis[i][j]=0ll;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=0;k<a[i].size();k++){
                int x=a[i][k].first;
                if(b[x][j]){
                    dis[i][j]=min(dis[i][j],(long long)b[x][i]+(long long)b[x][j]);
                    dis[j][i]=dis[i][j];
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        x=read(),y=read();
        long long ans=1e18;
        for(auto j:li[x]){
            for(auto k:li[y]){
                ans=min(ans,dis[j][k]+b[x][j]+b[y][k]);
            }
        }
        print(ans+w[x]+w[y]);
        putchar('\n');
    }
    return 0;
}