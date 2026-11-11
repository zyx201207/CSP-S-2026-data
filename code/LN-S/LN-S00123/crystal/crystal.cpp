#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int p;
bool check(int x){
    int cnt=0;
    p=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=x){
            p=i;
            cnt+=x-a[i];
        }
        if(cnt>m){
            return false;
        }
    }
    return cnt<=m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    long long l=a[1],r=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        l=min(a[i],l);
        r=max(a[i],r);
    }
    sort(a+1,a+n+1);
    int ans=1;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(mid)){
            ans=max(ans,p);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
