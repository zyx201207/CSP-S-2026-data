#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,ans;
    long long a[500001];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int j=0;
    long long need=0;
    for(int i=1;i<=n;i++){
        if(i>1) need+=(i-1-j)*(a[i]-a[i-1]);
        while(need>m) need-=a[i]-a[++j];
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
