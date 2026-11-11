#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5005,M=2000005;
int n,d,x[M],len[N],c[N],l[N],r[N];

int dou(int s){
    len[s]=0,c[s]=1;int cnt=0;
    for(int i=s+1;i<=n;i++)len[i]=1e16,c[i]=1;
    for(int i=s;i<n;i++){
        int x=len[i]+1;
        for(int j=i+1;j<=r[i];j++){
            if(x<len[j]){
                len[j]=x,c[j]=c[i];
            }else if(x==len[j])c[j]+=c[i];
        }
        if(c[i]==2&&len[i]<n)cnt++;
    }
    return cnt;
}

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    int R=1;
    for(int i=1;i<=n;i++){
        while(R+1<=n&&x[R+1]-x[i]<=d)R++;
        r[i]=R;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=dou(i);
    cout<<ans<<'\n';
}

void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    int D=x[2]-x[1],k=d/D;
    if(k<=1){cout<<"0\n";return;}
    int ans=0;
    for(int i=1;i<=n;i++)
        if(i+2*k-1<=n)ans++;
    cout<<ans<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,t;cin>>c>>t;
    if(c<=10)while(t--)solve();
    else if(c<=12)while(t--)solve2();
}
