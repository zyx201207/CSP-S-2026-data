#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=1,ans=1,cnt=0;
    b[1]=a[2]-a[1];
    for(long long r=2;r<=n;r++){
        cnt+=(r-l)*(a[r]-a[r-1]);
        while(cnt>m){
            cnt-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
