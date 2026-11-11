#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long f=1,c=a[2]-a[1];
    for(int i=1;i<n;i++){
        if(c!=a[i+1]-a[i]){
            f=0;
            break;
        }
    }
    if(f==1){
        for(int i=1;i<=n;i++){
            long long sum=(i-1)*c*i/2;
            if(m<sum){
                cout<<i-1<<'\n';
                return 0;
            }
        }
    }
    a[n+1]=1e13;
    for(int i=1;i<=n;i++){
        long long h=m,sum=0;
        if(a[i]==a[i+1]){
            continue;
        }
        for(int j=i;j>=1;j--){
            if(h>=a[i]-a[j]){
                h-=a[i]-a[j];
                sum++;
            }else{
                break;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans<<'\n';
    return 0;
}
