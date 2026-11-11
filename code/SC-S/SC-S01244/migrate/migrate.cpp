#include<bits/stdc++.h>
using namespace std;
const int N=2000009;
int c,_,n,cnt[309][309],dis[309][309],inq[309][309],ql,qr,mid;
struct det{int x,dis;}q[309];
bool vis[309][309];
long long d,a[N],ans,cf[N],ans0l,ans0r,ans1l,ans1r;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(cin>>c>>_;_--;){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=300){
            ans=0;
            memset(vis,0,sizeof vis);
            memset(dis,0x3f,sizeof dis);
            memset(cnt,0,sizeof cnt);
            for(int st=1;st<=n;st++){
                ql=1,qr=0;
                for(q[++qr]={st,0},dis[st][st]=0,inq[st][st]=1,cnt[st][st]=1;ql<=qr;){
                    det u=q[ql++];
                    vis[st][u.x]=1;
                    inq[st][u.x]=0;
                    for(int i=1;i<=n;i++)
                        if(abs(a[i]-a[u.x])<=d&&!vis[st][i]){
                            if(dis[st][i]==u.dis+1)cnt[st][i]+=cnt[st][u.x];
                            else if(!inq[st][i])dis[st][i]=u.dis+1,cnt[st][i]+=cnt[st][u.x],inq[st][i]=1,q[++qr]={i,u.dis+1};
                        }
                }
                for(int i=1;i<=n;i++)ans+=(cnt[st][i]==2);
            }
            cout<<ans/2<<'\n';
            continue;
        }
        if(c==11||c==12){
            cout<<max(0ll,d/(a[2]-a[1])>=2?n-(2*(d/(a[2]-a[1]))-1):0ll)<<'\n';
            continue;
        }
        if(c==13||c==14){
            for(int i=1;i<=n;i++)if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
                mid=i;
                break;
            }
            int l=1,r=0;
            for(int i=1;i<n;i++){
                while(l+1<=i&&a[i]-a[l]>d)l++;
                while(r+1<=n&&a[r+1]-a[i]<=d)r++;
                cf[l]++,cf[r+1]--;
            }
            cf[1]-=mid,cf[mid]+=mid,cf[mid+1]-=n-mid;
            ans0l=ans0r=ans1l=ans1r=0;
            for(int i=1;i<=n;i++)cf[i]+=cf[i-1],ans0l+=(cf[i]==0&&i<mid),ans0r+=(cf[i]==0&&i>mid),ans1l+=(cf[i]==1&&i<mid),ans1r+=(cf[i]==1&&i>mid);
            cout<<1ll*ans0l*ans1r+1ll*ans0r*ans1l<<'\n';
            for(int i=1;i<=n;i++)cf[i]=0;
            continue;
        }
    }
}