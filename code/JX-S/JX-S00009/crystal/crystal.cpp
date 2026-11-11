#include <bits/stdc++.h>
using namespace std;
int a[500005];
queue<long long>q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    q.push(a[1]);
    long long ans=0,len=1,sum=0;
    for(int i=2;i<=n;i++){
        q.push(a[i]);
        sum=sum+(len++)*(a[i]-a[i-1]);
        if(sum>m){
            while(1){
                q.pop();
                sum-=(a[i]-q.front());
                len--;
                if(sum<=m) break;
            }
        }
        ans=max(ans,len);
    }
    cout<<ans;
    return 0;
}
