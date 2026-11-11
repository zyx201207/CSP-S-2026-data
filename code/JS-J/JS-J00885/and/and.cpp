#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,f=1,mx,ans,test7,a[N];
bool check(long long x){
    int cnt=0;
    for(int i=1;i<=n;i++)if((x&a[i])>=x)cnt++;
    return cnt>=m;
}
bool ck(long long ai){
    long long x=1;
    while(x<=ai)x*=2;
    if(ai==x-1)return 1;
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)test7=a[1];
        else test7&=a[i];
        if(!ck(a[i]))f=0;
    }sort(a+1,a+n+1);
    mx=a[n-m+1];
    if(m==1){
        cout<<mx<<'\n';
        return 0;
    }
    if(m==n){
        cout<<test7<<'\n';
        return 0;
    }
    if(f){
        ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ans&=a[i];
        }
        cout<<ans<<'\n';
        return 0;
    }
    for(int i=mx;i>=0;i--){
        if(check(i)){
            cout<<i<<'\n';
            return 0;
        }
    }
    return 0;
}
