#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d;
long long x[2000005],minn[20005][20005],cnnt[20005][20005],ans;
void dfs(int f,int now,int y,long long z){
    if(now==y){
        minn[f][y]=min(minn[f][y],z);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(x[i]>x[now] and x[i]<=x[y] and x[i]-x[now]<=d){
            z+=(x[i]-x[now])*(x[i]-x[now]);
            dfs(f,i,y,z);
        }

    }
}
void df2(int f,int now,int y,long long z){
    if(now==y){
        if(z==minn[f][y]){
            cnnt[f][y]++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(x[i]>x[now] and x[i]<=x[y] and x[i]-x[now]<=d){
            z+=(x[i]-x[now])*(x[i]-x[now]);
            dfs(f,i,y,z);
        }

    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                minn[i][j]=INT_MAX/2;
                cnnt[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dfs(i,i,j,0);
                df2(i,i,j,0);
                if(cnnt[i][j]==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}
