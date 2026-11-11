#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,tot,x[2000005],final;

void dfs(int to,int now,int cnt){
    if(now==to){
        if(cnt<ans){
            tot=1;
            ans=cnt;
        }else if(cnt==ans){
            ++tot;
        }
        //cout<<"cnt: "<<cnt<<" ans: "<<ans<<endl;
        return;
    }
    for(int i=now+1;i<n;++i){
        if(abs(x[i]-x[now])<=d&&i!=now){
            dfs(to,i,cnt+1);
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;
    for(int i=1;i<=t;++i){
        final=0;
        cin>>n>>d;
        for(int j=0;j<n;++j){
            cin>>x[j];
        }
        for(int u=0;u<n;++u){
            for(int v=u+1;v<n;++v){
                ans=4e18;
                tot=0;
                dfs(v,u,0);
                //cout<<u<<" "<<v<<" res: "<<tot<<endl;
                if(tot==2){
                    final++;
                }
            }
        }
        cout<<final<<"\n";
    }
    return 0;
}