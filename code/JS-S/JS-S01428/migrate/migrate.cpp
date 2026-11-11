#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define F1 freopen("migrate.in","r",stdin)
#define F2 freopen("migrate.out","w",stdout)
void io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll c,t,a[2000000+100],n,d,in[2000000+100],out[2000000+100],dis[2000000+100],ans;
ll fnd(ll a){
    if(dis[a]==a)return a;
    return dis[a]=fnd(dis[a]);
}
void marge(int u,int v){
    dis[fnd(u)]=dis[fnd(v)];
}
int main(){
    F1;F2;
    io();
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)dis[i]=i;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;a[j]<=a[i]+d&&j<=n;j++){
                marge(i,j);
                out[i]++;
                in[j]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(out[i]==2){
                for(int j=i+1;fnd(i)==fnd(j)&&j<=n;j++){
                    if(a[j]<=a[i]+d)continue;
                    if(in[j]==2){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//RP++;
//I like zyz in my class(17);
