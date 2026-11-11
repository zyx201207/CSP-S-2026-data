#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,x[N];int c,t;
struct node{
    int x,len,pos;
};
void solve(){
    memset(x,0,sizeof(x));
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(c==11||c==12){
        if(d<(x[2]-x[1])){
            cout<<0<<'\n';
            return;
        }
        else if(x[3]-x[1]<=d){
            cout<<0<<'\n';
            return;
        }
        else{
            cout<<n*(n-1)/2<<'\n';
            return;
        }
    }
    int pairs=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            queue<node>q;
            q.push({x[i],0,i});
            int cnt=0,ans;
            while(!q.empty()){
                auto u=q.front();
                q.pop();
                if(u.x==x[j]){
                    cnt++;
                    if(cnt==1){ans=u.len;}
                    if(cnt==2){
                        if(u.len!=ans){
                            break;
                        }
                    }
                    if(cnt==3){
                        if(u.len!=ans){
                            pairs++;
                            //cout<<i<<' '<<j<<'\n';
                        }
                        break;
                    }
                }
                else{
                    for(int k=u.pos+1;k<=j;k++){
                        if(x[k]-u.x<=d){
                            q.push(node{x[k],u.len+1,k});
                        }
                    }
                }
            }
        }
    }
    cout<<pairs<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
}