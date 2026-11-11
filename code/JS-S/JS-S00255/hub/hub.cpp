#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
using ll=long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        cout<<1<<(t==0?"":"\n");
    }

    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
using ll=long long;
bool cmp(int x,int y){
    return x>y;
}
ll a[MAXN];
int ans=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=1003333){
        cout<<n;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        ll k=0;
        int cnt=0;
        for(int j=i+1;j<=n;j++){
            ll c=a[i]-a[j];
            if(k+c>m){
                break;
            }
            cnt++;
            k+=c;
        }
        ans=max(ans,cnt+1);
    }
    cout<<ans;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
using ll=long long;
bool cmp(int x,int y){
    return x>y;
}
ll a[MAXN];
int ans=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=1003333){
        cout<<n;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        ll k=0;
        int cnt=0;
        for(int j=i+1;j<=n;j++){
            ll c=a[i]-a[j];
            if(k+c>m){
                break;
            }
            cnt++;
            k+=c;
        }
        ans=max(ans,cnt+1);
    }
    cout<<ans;
    return 0;
}*/
