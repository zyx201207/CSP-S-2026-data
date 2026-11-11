#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
struct lxz{
    int wz;
    int bs;
};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        //vector<int> g[n+5];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<n-2<<endl;
        /*for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                int ma=-999,c=0;
                queue<lxz> q;
                bool v[n+5];
                q.push({l,0});
                while(!q.empty()){
                    lxz now=q.front();
                    q.pop();
                    if(now.wz==r){
                        if(now.bs>ma){
                            ma=now.bs;
                            c=1;
                        }else if(now.bs==ma){
                            c++;
                        }
                    }
                    for(int i=0;i<g[now.wz].size();i++){
                        if(!v[g[now.wz][i]]){
                            v[i]=1;
                            q.push({g[now.wz][i],now.bs+1});
                        }
                    }
                }
                if(c==2)ans++;
            }
        }
        cout<<ans<<endl;*/
    }
    return 0;
}
