#include<bits/stdc++.h>
using namespace std;
long long t,c,n,d,cnt;
const int maxn=2e6+10;
long long a[maxn];
struct node{
    long long l,r;
}G[maxn];
bool cmp(node a,node b){
    if(a.l!=b.l)return a.l<b.l;
    else return a.r<b.r;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        a[n+1]=a[n]+1e18;
        queue<long long>q;
        q.push(a[1]);
        for(int i=2;i<=n+1;i++){
            if(a[i]-q.front()>d){
                G[++cnt]={q.front(),a[i-1]};
            }
            q.push(a[i]);
            while(a[i]-q.front()>d)q.pop();
        }
        sort(G+1,G+cnt+1,cmp);
        long long ans=0;
        for(int i=1;i<cnt;i++){
            if(G[i].r>G[i+1].l&&G[i].r-G[i+1].l==1)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
