#include<bits/stdc++.h>
#include<bits/extc++.h>
#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
const int MAXN=2e6;
int c,n,nxt[MAXN+11],dist[555][555];
long long d,x[MAXN+11];
void main_init(){
    cin>>c;
    return;
}
void solve(){
    for(int i=1;i<=n;i++)
        nxt[i]=-1;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    if(11<=c&&c<=12){
        long long s=d/(x[2]-x[1]);
        if(s<=1)
            return cout<<0<<endl,void();
        long long res=0;
        for(int l=1;l<=n;l++)
            res+=int(l+2*s-1<=n);
        cout<<res<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        {
            int l=i+1,r=n,pos=-1;
            while(l<=r){
                int mid=l+r>>1;
                if(x[mid]-x[i]<=d)
                    l=mid+1,pos=mid;
                else
                    r=mid-1;
            }
            nxt[i]=pos;
        }
    }
    for(int l=1;l<=n;l++)
        for(int r=l+1;r<=n;r++){
            int t=l,cnt=0;
            while((~t)&&t<r)
                t=nxt[t],cnt++;
            dist[l][r]=cnt;
        }
    int res=0;
    for(int l=1;l<=n;l++)
        for(int r=l+1;r<=n;r++){
            int cnt=0;
            for(int k=l+1;k<=r-1;k++)
                cnt+=int(dist[l][k]+dist[k][r]==dist[l][r]);
            res+=int(cnt==2);
        }
    cout<<res<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    main_init();
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}