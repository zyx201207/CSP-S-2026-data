#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long M=1e18;
long long n,m,a[N],h[N],sum=0,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int x=1;
    for(int i=1;i<=n;i++){
        int w=a[i]-a[i-1];
        while(m-w*(i-x)<sum){
            sum-=h[x];
            h[x+1]+=h[x];
            x++;
        }
        sum+=w*(i-x);
        h[x]+=w;
        h[i]-=w;
        ans=max(ans,(long long)(i-x+1));
    }
    cout<<ans;
    return 0;
}
