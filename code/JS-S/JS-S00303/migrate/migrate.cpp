#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define m_p make_pair
#define P pair<int,int>
#define lowbit(x) (x&(-x))
#define fr first
#define sc second
typedef long long ll;
ll tmp[2000005];
ll a[2000005];
int pre[2000005],nxt[2000005];
ll Sp[2000005],Sn[2000005];
int cnt[2000005];
ll L[2000005],R[2000005];
ll sol(int n,ll d){
    //cout<<n<<" ";
    int j=0;
    for(int i=0;i<n;i++){
        while(j<n&&a[j]-a[i]<=d) j++;
        nxt[i]=j-1;
    }
    j=n-1;
    for(int i=n-1;i>=0;i--){
        while(j>=0&&a[i]-a[j]<=d) j--;
        pre[i]=j+1;
    }
    //for(int i=0;i<n;i++) cout<<pre[i]<<" "<<nxt[i]<<endl;
    for(int i=0;i<n+2;i++) Sn[i]=Sp[i]=0;
    for(int i=0;i<n+2;i++) cnt[i]=0;
    Sn[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(pre[nxt[i]]==i) Sn[i]=Sn[nxt[i]];
        for(int j=nxt[i];j<nxt[i+1];j++) cnt[pre[j]]--;
        cnt[pre[i]]++;
        Sn[i]+=1+cnt[i];
    }
    for(int i=0;i<n+2;i++) cnt[i]=0;
    Sp[0]=1;
    for(int i=1;i<n;i++){
        if(nxt[pre[i]]==i){
            Sp[i]=Sp[pre[i]];
            //cout<<i<<endl;
        }
        for(int j=pre[i];j>pre[i-1];j--) cnt[nxt[j]]--;
        cnt[nxt[i]]++;
        Sp[i]+=1+cnt[i];
    }
    ll ans=0;
    for(int i=0;i<n+2;i++) L[i]=R[i]=0;
    for(int i=0;i<n-1;i++){
        int x=nxt[i];
        if(x!=i+1&&pre[x-1]!=i) L[x-1]++;
    }
    for(int i=n-1;i>0;i--){
        int x=pre[i];
        if(x!=i-1&&nxt[x+1]!=i) R[x]++;
    }
    //for(int i=0;i<n;i++) cout<<nxt[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++) cout<<pre[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++) cout<<Sp[i]<<" ";cout<<endl;
    for(int i=1;i<n-2;i++){
        int a=pre[i],b=nxt[i+1];
        //cout<<i<<" "<<a<<endl;
        if(nxt[a]==i+1&&pre[b]==i) ans+=1ll*Sp[a]*Sn[b];
        //cout<<ans<<" ";
        if(nxt[a]==i+1) ans+=1ll*R[i]*Sp[a];
        //cout<<ans<<" ";
        if(pre[b]==i) ans+=1ll*L[i]*Sn[b];
        //cout<<ans<<" ";
        ans+=1ll*L[i]*R[i];
        //cout<<ans<<endl;
    }
    return ans;
}
ll go(ll d,int l,int r){
    for(int i=l;i<=r;i++) a[i-l]=tmp[i];
    return sol(r-l+1,d);
}
void solve(){
    int n;ll d;cin>>n>>d;
    for(int i=0;i<n;i++) cin>>tmp[i];
    int lst=0;
    ll ans=0;
    for(int i=0;i+1<n;i++){
        if(tmp[i+1]-tmp[i]>d){
            ans+=go(d,lst,i);
            lst=i+1;
        }
    }
    ans+=go(d,lst,n-1);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--) solve();
    return 0;
}