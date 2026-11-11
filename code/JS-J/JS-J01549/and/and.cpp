#include <bits/stdc++.h>
using namespace std;
int n,m,a;
int p[200005][30];
int ans;
int flag[200005];
int sum;
int g[31];
void pl(int j,int x){
    int w=x;
    for(int i=29;i>=0;i--){
        if(w>=g[i]) p[j][i]=1,w-=g[i];
    }
}int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    g[0]=1;
    for(int i=1;i<=29;i++) g[i]=g[i-1]*2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        flag[i]=1;
        pl(i,a);
    }for(int i=29;i>=0;i--){
        sum=0;
        for(int j=1;j<=n;j++){
            if(!flag[j]) continue;
            if(p[j][i]==1) sum++;
        }if(sum>=m){
            ans+=g[i];
            for(int j=1;j<=n;j++)
                if(p[j][i]==0) flag[j]=0;
        }
    }cout<<ans;
    return 0;
}
