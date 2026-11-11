#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxn=-1e9;
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=i-1;j<=n-1;j++){
            sum+=a[i]-a[j];
            if(j>=m){
                break;
            }
        }
        maxn=max(maxn,sum);
    }
    int ans;
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=i-1;j<=n-1;j++){
            sum+=a[i]-a[j];
            if(j>=m){
                break;
            }
        }
        if(sum==maxn)ans=i;
    }
    cout<<ans-1;
    fclose(stdout);
    return 0;
}
