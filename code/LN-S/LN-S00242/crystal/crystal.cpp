#include<bits/stdc++.h>
using namespace std;
struct p{
    int a;
    int b;

}ans[1000001];
bool cmp(p n,p m){
    return n.b<m.b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+1];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long dp[n+1];
    p cnt[100001];
    dp[0]=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]+=abs(a[i]-a[j]);


        }
        cnt[i].a=i;
        cnt[i].b=dp[i];

    }
    sort(cnt+1,cnt+n+1,cmp);

   int i=1;
    while(cnt[i].b<m){
        i++;
    }
    cout<<i;
    return 0;
}
