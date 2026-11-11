#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int N=2e5+7;
int n,m;
int a[N],x;
int ans;
bool cka(){
    for(int i=1;i<=n;i++)
        if(a[i]!=i)
            return 0;
    return 1;
}
bool ckb(int &v){
    int c=a[2]-a[1];
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=c)
            return 0;
    v=c;
    return 1;
}
void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(cka()){
        int l=1,r=4e9,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            cerr<<l<<' '<<r<<' '<<mid<<' '<<ans<<endl;
            if(mid*(mid+1)/2<m)l=mid+1,ans=mid;
            else if(mid*(mid+1)/2==m)l=r+1,ans=mid;
            else r=mid-1;
        }
        cout<<min(ans+1,n);
        return ;
    }
    if(ckb(x)){
        int l=1,r=4e9,ans=0;
        m/=x;
        while(l<=r){
            int mid=(l+r)>>1;
            cerr<<l<<' '<<r<<' '<<mid<<' '<<ans<<endl;
            if(mid*(mid+1)/2<m)l=mid+1,ans=mid;
            else if(mid*(mid+1)/2==m)l=r+1,ans=mid;
            else r=mid-1;
        }
        cout<<min(ans+1,n);
        return ;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int sum=0,j;
        for(j=i-1;j;j--)
            if(sum+a[i]-a[j]<=m)
                sum+=a[i]-a[j];
            else break;
        ans=max(ans,i-j);
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int _77231=1;
    // cin>>_77231;
    while(_77231--)mian();
    return 0;
}