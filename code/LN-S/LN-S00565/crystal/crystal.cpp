#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
long long m,a[500010],sum;
queue<long long>q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cnt++;
        if(i>1)sum+=(i-1)*(a[i]-a[i-1]);
        q.push(a[i]);
        while(sum>m){
            cnt--;
            sum-=a[i]-q.front();
            q.pop();
        }
        ans=max(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}
