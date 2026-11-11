#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int MAXN=5e5+5;

int n,m,a[MAXN],d[MAXN],ans=-1;


signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    int p=1,cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=p+1;j<=n;j++){
            cnt+=d[j]*(j-i);
            //cout<<cnt<<endl;
            if(cnt>m){
                cnt-=d[j]*(j-i);
                cnt-=(a[j-1]-a[i]);
                p=j-1;
                break;
            }if(j==n) p=j;
        }
        //cout<<p<<endl;
        //cout<<endl;
        ans=max(ans,p-i+1);
    }
    cout<<ans;
    return 0;
}

//id:JS-S00335
//This is the code for crystal.
//Last modified on Oct.31st 16:51
//100 pts
//All samples are correct.
//O(n)
//password:Oct31==Dec25?
//Are you with me? Is it fiction?
