#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
ll n,d,x[N];
ll c[N],dis[N],s[N],dq[N],h,t,q[N],qh,qt;
void solve40(){// 40 points
    ll ans=0;
    for(int u=1;u<=n;u++){
        for(int i=0;i<=n;i++){
            c[i]=0;
            s[i]=0;
        }
        dis[u]=0;
        s[u]=1;
        h=1,t=0;qh=1,qt=0;
        dq[++t]=u;
        q[++qt]=u;
        c[dis[u]]+=s[u];
        for(int v=u+1;v<=n;v++){
            while(h<=t){ // time out 
                int idx=dq[h];
                if(x[idx]+d<x[v]){
                    h++;
                }
                else break;
            }
            while(qh<=qt){ // timeout
                int idx=q[qh];
                if(x[idx]+d<x[v]){
                    qh++;
                    c[dis[idx]]-=s[idx];
                }else break;
            }
            if(h>t)dis[v]=1e18;
            else {
                dis[v]=dis[dq[h]]+1;
                s[v]=c[dis[dq[h]]];
            }
            if(s[v]==2){
                ans++;
                //cout<<u<<" "<<v<<" "<<dis[v]<<"\n";
            }
            if(dis[v]<=n){ // push
                while(h<=t){
                    int idx=dq[t];
                    if(dis[idx]>=dis[v])t--;
                    else break;
                }
                dq[++t]=v; 
                
                q[++qt]=v;
                c[dis[v]]+=s[v];
            }
        }
    }
    cout<<ans<<"\n";
}
void solve48(){
    int nxt=1;
    while(nxt<n&&x[nxt+1]<=x[1]+d)nxt++;
    nxt--;
    if(nxt<=1){
        cout<<"0\n";
        return;
    }
    ll y=nxt*2;//u,u+y-1
    ll ans=max(0ll,n-y+1);
    cout<<ans<<"\n";
}
// void solve56(){
//     ll ans=0;
//     for(int u=1;u<n;u++){
//         int A=upper_bound(x+1,x+n+1,x[u]+d)-x;// v in [A~n]
//         if(A>n)continue;
//         int B=A-2;
//         if(B>u){
//             int L=x[B-1]+d+1,R=x[B]+d;
//             ans+=upper_bound(x+A,x+n+1,R)-lower_bound(x+A,x+n+1,L);
//         }
//     }
//     cout<<ans<<"\n";
// }

// ll f[N],g[N],cg[N],lo[N],ro[N],cro[N];

// void solve100(){
//     ll ans=0;
//     for(int i=1;i<n;i++){
//         int A=lower_bound(x+1,x+n+1,x[i]-d)-x;
//         if(A==i)continue;
//         if(x[i+1]-d<=x[A])continue;
//         f[i]=f[A]+1;
//     }
//     for(int i=n;i>1;i--){
//         int A=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
//         if(A==i)continue;
//         if(x[i-1]+d>=x[A])continue;
//         g[i]=g[A]+1;
//     }
//     for(int i=1;i<=n;i++){
//         lo[i]=upper_bound(x+1,x+n+1,x[i]-1)-lower_bound(x+1,x+n+1,x[i]-d);
//         ro[i]=upper_bound(x+1,x+n+1,x[i]+d)-lower_bound(x+1,x+n+1,x[i]+1);
//         cro[i]=cro[i-1]+ro[i];
//     }
//     cg[n+1]=0;
//     for(int i=n;i>1;i--)cg[i]=cg[i+1]+g[i];
//     for(int u=1;u<n;u++){
//         int A=upper_bound(x+1,x+n+1,x[u]+d)-x-1;// v in [A~n], u -> t -> v
//         int B=A-1; // u -> A,B -> v
//         if(B>u){
//             int L=x[B-1]+d+1,R=x[B]+d;
//             int pL=lower_bound(x+1,x+n+1,L)-x;
//             int pR=upper_bound(x+1,x+n+1,R)-x-1;
//             ans+=1ll*f[u]*(cg[pR]-cg[pL-1]);
//             ans++;
//             //ans+=1ll*lo[u]*(cro[pR]-cro[pR-1]);
//         }
//     }
//     cout<<ans<<"\n";
// }

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(x[n]-x[1]<=d){
        cout<<"0\n";
        return;
    }
    if(n<=5000){
        solve40();
        return;
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    ll dd=x[2]-x[1],f=1;
    for(int i=3;i<=n;i++){
        if(x[i]-x[i-1]!=dd)f=0;
    }
    if(f){
        solve48();
        return;
    }
    // f=0;
    // for(int i=1;i<=n;i++){
    //     if(x[i]-d<=x[1]&&x[i]+d>=x[n])f=1;
    // }
    // if(f){
    //     solve56();
    //     return;
    // }
    //cout<<"100points\n";
    //solve100();
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}