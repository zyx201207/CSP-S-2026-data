#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long a[N],s[N][N];
long long n,m,ma=-1;
void bfs(long long sum,long long c,long long ans,long long j){
    /*
    cout<<sum;
    for(int i=1;i<=sum;i++) cout<<"-";
    cout<<" "<<c<<" "<<ans<<" "<<j<<endl;
    */
    if(ans>m){
        return ;
    }
    ma=max(sum-1,ma);
    for(int i=c;i>=1;i--){
        if(sum==1) bfs(sum+1,i-1,ans,i);
        else bfs(sum+1,i-1,ans+s[i][j],j);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    s[1][1]=0;
    for(int i=2;i<=n;i++){
        s[i-1][i]=a[i]-a[i-1];
        for(int j=2;j<i;j++){
            s[i-j][i]=s[i-j][i-1]+s[i-1][i];
        }
    }
    bfs(1,n,0,n);
    cout<<ma;
    return 0;
}
