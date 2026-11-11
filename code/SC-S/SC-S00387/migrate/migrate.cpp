#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,c;
int x[N],dis[N],f[N],nxt[N],lst[N],t[N];
int sum[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        lst[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
    }
    if(c<=10){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++)dis[j]=-1,f[j]=0,t[j]=0,sum[j]=0;
            int now=i,d=0;
            dis[i]=0;
            while(1){
                for(int j=now;j>=i;j--){
                    if(dis[j]!=-1)break;
                    dis[j]=d;
                }
                if(nxt[now]==now)break;
                now=nxt[now],d++;
            }
            f[i]=1,sum[i]=1;
            for(int j=n;j>=i;j--){
                if(dis[j]==-1)continue;
                if(dis[j+1]!=dis[j])t[j]=j;
                else t[j]=t[j+1];
            }
            for(int j=i+1;j<=n;j++){
                int pos=max(lst[j],i),pos1=t[pos];
                f[j]=sum[pos1]-sum[pos-1];
                f[j]=min(f[j],3ll);
                if(f[j]==2)ans++;
                sum[j]=sum[j-1]+f[j];
            }
        }
        cout<<ans<<'\n';
        return;
    }
    if(c==11||c==12){
        int ans=0;
        for(int i=1;i<=1;i++){
            for(int j=0;j<=n;j++)dis[j]=-1,f[j]=0,t[j]=0,sum[j]=0;
            int now=i,d=0;
            dis[i]=0;
            while(1){
                for(int j=now;j>=i;j--){
                    if(dis[j]!=-1)break;
                    dis[j]=d;
                }
                if(nxt[now]==now)break;
                now=nxt[now],d++;
            }
            f[i]=1,sum[i]=1;
            for(int j=n;j>=i;j--){
                if(dis[j]==-1)continue;
                if(dis[j+1]!=dis[j])t[j]=j;
                else t[j]=t[j+1];
            }
            for(int j=i+1;j<=n;j++){
                int pos=max(lst[j],i),pos1=t[pos];
                f[j]=sum[pos1]-sum[pos-1];
                f[j]=min(f[j],3ll);
                if(f[j]==2)ans+=n-j+1;
                sum[j]=sum[j-1]+f[j];
            }
        }
        cout<<ans<<'\n';
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int A=nxt[i],B=A-1,C=B-1;
        if(B<=i)B=0;
        if(C<=i)C=0;
        while(1){
            int l=max(A+1,nxt[C]+1),r=nxt[B];
            if(r>=l)ans+=r-l+1;
            if(A==n)break;
            vector<int>vec;
            if(nxt[A]==A)break;
            vec.push_back(nxt[A]);
            if(nxt[A]-1>A)vec.push_back(nxt[A]-1);
            if(nxt[A]-2>A)vec.push_back(nxt[A]-2);
            vec.push_back(nxt[B]);
            if(nxt[B]-1>B)vec.push_back(nxt[B]-1);
            if(nxt[B]-2>B)vec.push_back(nxt[B]-2);
            vec.push_back(nxt[C]);
            if(nxt[C]-1>C)vec.push_back(nxt[C]-1);
            if(nxt[C]-2>C)vec.push_back(nxt[C]-2);
            sort(vec.begin(),vec.end(),[&](int x,int y){return x>y;});
            A=vec[0],B=vec[1],C=vec[2];
            if(A==B&&B==C)break;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}