#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<'\n'
#define zero(a) memset(a,0,sizeof a)
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
const int MAX=(1<<31)-1;
const int MOD=1e9+7;
const int N=500010;
int a[N],n,sum[N],m;
bool check(int C){
    if(C==1) return true;
    int L,R;
    L=C-1;
    R=0;
    int lcnt;
    for(int i=L;(i+R)<n;i++){
        lcnt=a[i]*L;
        lcnt=lcnt-sum[i-1];
        if(i!=L) lcnt+=sum[i-L-1];
        //rcnt=sum[i+R]-sum[i]-a[i]*R;
        if(lcnt<=m)
        {
            //cout<<lcnt<<" "<<rcnt<<" "<<cnt<<" "<<m<<" "<<i<<endl;
            return true;
        }
    }
    return false;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    sum[0]=a[0];
    for(int i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
    int l=0,r=n;
    while(l<r){
        //cout<<l<<" "<<r<<endl;
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}
//14:53
