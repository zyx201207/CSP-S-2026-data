#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long a[N],q[N];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //q[i]=q[i-1]+a[i]+m;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    long long ans=-1;
    for(long long i=1;i<=n;i++){
            for(long long j=0;j<i;j++){
                if((q[i]+m-q[j])%a[i]==0&&(q[i]+m-q[j])/a[i]<=i-j){ans=max(ans,i-j);}
            }

    }
    cout<<ans;


    return 0;
}
