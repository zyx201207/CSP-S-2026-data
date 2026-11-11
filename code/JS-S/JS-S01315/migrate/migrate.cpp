#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int a[MAXN],p[MAXN];
void solve(){
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=n;i>=1;i--){
            for(int s=1;s<i;s++){
                int bi=0,tot=1,en;
                p[tot]=i;
                while(p[tot]!=p[tot-1]){
                    bi=lower_bound(a+s,a+1+p[tot],a[p[tot]]-d)-a;
                    p[++tot]=bi;
                }
                bool f=0,ex=0;
                for(int j=2;j<=tot-2;j++){
                    for(int k=p[j]+1;k<p[j-1];k++){
                        if(a[p[j-1]]-a[k]<=d&&a[k]-a[p[j+1]]<=d){
                            if(f){
                                ex=1;
                                break;
                            }
                            f=1;
                        }else break;
                    }
                    if(ex)break;
                    if(f)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    solve();
    return 0;
}
