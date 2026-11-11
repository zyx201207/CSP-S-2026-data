#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d;
long long x[1000005];
int minidis=INT_MAX;
int miniway=0;
void dfs(int p,int dis,int ed){
    if(p==ed){
        if(minidis>dis){
            minidis=dis;
            miniway=1;
        }else if(minidis==dis){
            miniway++;
        }
        return ;
    }else if(dis>minidis) return;
    int flag=0;
    for(int i=ed;i>=p+1;i--){
        if(x[i]-x[p]<=d&&flag<=2){
            dfs(i,dis+1,ed);
            flag++;
        }else if(flag>2)return;
    }
    return;
}
bool check(int s,int e){
    dfs(s,0,e);
    minidis=INT_MAX;

    if(miniway==2){
        miniway=0;
        return 1;
    }
    else {
        miniway=0;
        return 0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }

}
/**/
