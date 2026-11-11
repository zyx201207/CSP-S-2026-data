#include<bits/stdc++.h>
using namespace std;
long long n,m,f,temp,ans=1,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    a[n-1]-=a[n-2];
    for(int i=n-2;i>0;i--){
        a[i]-=a[i-1];
        f|=(a[i]!=a[i+1]);
    }
    if(!f){
        for(long long i=1;i<n;i++){
            if(a[i]*i<=m){
                m-=a[i]*i;
            }else{
                cout << i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    for(long long i=0;i<=n-ans;i++){
        temp=m;
        for(long long j=i;j<n;j++){
            if(a[j]*(j-i)<=temp){
                temp-=a[j]*(j-i);
            }else{
                ans=max(ans,j-i);
                break;
            }
        }
    }
    cout << ans;
}
