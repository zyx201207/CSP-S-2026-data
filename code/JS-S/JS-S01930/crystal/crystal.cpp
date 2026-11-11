#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define u_mp unordered_map
#define u_st unordered_set
#define prio_q priority_queue
#define ll long long
#define int ll
const int N=5e5+5;
int n,m;
int a[N],sum[N];
int solve(int p){
    int l=1,r=p,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[p]*mid-(sum[p]-sum[p-mid])>m){
            r=mid-1;
        }else{
            l=mid+1;
            ans=mid;
        }
    }
    return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
        //cerr<<i<<':'<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
