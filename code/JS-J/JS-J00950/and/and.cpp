#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long s[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]&a[i];
    }
    sort(a+1,a+n+1);
    cout<<s[n]<<endl;
    if(m==1){
        cout<<a[n+1]<<endl;
        return 0;
    }
    if(m==n){
        cout<<s[n]<<endl;
        return 0;
    }
    if(m==2){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i&j>ans){
                    ans=i&j;
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==n-1){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            long long sum=1;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    sum&=a[j];
                }
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}
