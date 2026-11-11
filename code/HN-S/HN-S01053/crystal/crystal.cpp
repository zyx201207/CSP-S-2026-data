#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pq priority_queue
#define popcount(x) __builtin_popcount(x)
#define endl '\n'
int n,m;
const int N = 5e5+10;
int a[N],cf[N],c[N],L[N],tot,mx;
int sum[N];
bool check(int i,int x){
    int len=i-x;
    return a[i]*len-(sum[i-1]-sum[x-1])<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int cnt=1;cf[1]=1;
    int lst=a[n];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i-1]!=a[i]){
            //q.push({a[i]-a[i-1],cnt,i-1});
            c[i-1]=cnt;mx=max(mx,cnt);
            cnt=1;    
        }else{
            ++cnt;
        }
        cf[i]=a[i]-a[i-1];
    }
    c[n]=cnt;
    for(int i=n;i>=1;i--){
        if(!c[i])c[i]=c[i+1];
    }
    int ans=mx;
    for(int i=n;i>=1;i--){
        if(a[i-1]==a[i])continue;
        int l=1,r=i,res=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(i,mid)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,c[i]+(i-res));
    }
    cout<<ans;
    return 0;
}