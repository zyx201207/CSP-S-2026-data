#include<bits/stdc++.h>
using namespace std;
long long n,m,total,mid;
long long a[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool q=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>1;i--){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]) q=0;
    }
    if(q==1){
        long long ans=1;
        long long chen=a[2]-a[1];
        for(int i=1;i<n;i++){
            m-=i*chen;
            if(m<0) break;
            ans++;
        }
        cout<<ans;
        return 0;
    }

    sort(a+1,a+n+1);
    long long maxn=-1;
    for(int i=n;i>=2;i--){
        long long mm=m;
        long long ans=1;
        for(int j=i-1;;j--){
            long long cha=a[i]-a[j];
            mm-=cha;
            if(mm<0) break;
            ans++;
        }
        maxn=max(maxn,ans);
        if(maxn==i) break;
    }
    cout<<maxn;
    return 0;
}
