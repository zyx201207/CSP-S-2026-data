#include<bits/stdc++.h>
const int N=5e5+10;
using namespace std;
long long n,m;
long long a[N];
long long s[N];
bool check(int p,int i){
    long long sum=s[i-1]-s[p-1];
    long long need=(long long)(i-p)*a[i];
    //if(need<sum&&i<=5) cout<<i<<" "<<s[i-1]<<" "<<s[p-1]<<endl;
    return m>=need-sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int res=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        res=max(res,i-ans+1);
    }
    cout<<res<<endl;
    return 0;
}
