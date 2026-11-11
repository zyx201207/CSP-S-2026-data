#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=0,mm=0;
bool f_1=1,f_2=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=i) f_1=0;
        if(i!=n){
            if(a[i+1]-a[i]!=a[2]-a[1]) f_2=0;
        }
    }
    if(f_1){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if((sum+m)/i<i){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    if(f_2){
        int sum=0;
        for(int i=2;i<=n;i++){
            sum+=a[i]-a[1];
            if(sum>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        mm=0;
        for(int j=i-1;j>=1;j--){
            mm+=abs(a[i]-a[j]);
            if(mm>m){
                ans=max(ans,i-j);
                break;
            }
            if(j==1){
                ans=max(ans,i);
            }
        }
    }
    if(ans==0) ans==1;
    cout<<ans;
    return 0;
}
