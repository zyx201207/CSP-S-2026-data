#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+500;
LL a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    queue<LL> qu;
    qu.push(a[1]);
    LL op=a[1],maxs=0,sum=0,ans=1;
    for(LL i=2;i<=n;i++){
        sum+=(a[i]-op)*ans;
        op=a[i];
        ans++;
        while(sum>m){
            sum-=(op-qu.front());
            qu.pop();
            ans--;
        }
        qu.push(a[i]);
        maxs=max(maxs,ans);
    }
    cout<<maxs;
    return 0;
}
