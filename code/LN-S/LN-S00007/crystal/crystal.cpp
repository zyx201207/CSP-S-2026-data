#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],c[maxn],s[maxn],ans;
bool cmp(int p,int q){
    return p>q;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int flg=1;
    for(int i=1;i<n;i++){
        c[i]=a[i]-a[i+1];
        s[i]=s[i-1]+c[i];
        if(c[i]<=m)flg=0;
    }
    if(flg){
        cout<<0<<"\n";
        return 0;
    }
    int i=0,head=1,tail=0,sum=0,q[maxn]={};
    while(++i<n){
        q[++tail]=i;
        sum+=s[i]-s[q[head]-1];
        //cout<<i<<' '<<sum<<endl;
        while(sum>m && head<=tail){
            //cout<<i<<' '<<sum<<' '<<c[q[head]]<<' '<<c[q[tail]]<<endl;
            sum-=c[q[head]]*(tail-head+1);
            ++head;
            //cout<<sum<<endl;
        }
        ans=max(ans,tail-head+2);
    }
    cout<<ans<<"\n";
    return 0;
}
