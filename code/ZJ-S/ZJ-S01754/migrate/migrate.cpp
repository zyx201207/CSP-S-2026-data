#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll a[N];
int n,c,t;
ll d;
void solve(){
    vector<pair<int,int>> f(n+2);
    vector<int> s(n+2);
    int head=1,tail=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        f[i]={1,1};
        head=1,tail=0;
        s[++tail]=i;
        for(int j=i+1;j<=n;j++){
            while(head<=tail&&a[s[head]]+d<a[j])head++;
            if(head>tail)break;
            int minm=f[s[head]].first,ct=0;
            for(int k=head;k<=tail;k++){
                if(f[s[k]].first==minm){
                    ct+=f[s[k]].second;
                }
                if(ct>2)break;
            }
            f[j]={minm+1,ct};
            while(head<=tail&&f[s[tail]].first>f[j].first)tail--;
            s[++tail]=j;
            if(f[j].second==2)ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            solve();
        }       
    }else{
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            ll del=a[2]-a[1];
            ll c=d/del;
            ll ans=max(n-2*c+1,0ll);
            if(c<=1)ans=0;
            cout<<ans<<"\n";
        }
    }
}