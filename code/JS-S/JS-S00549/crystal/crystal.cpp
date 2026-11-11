#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cob;
long long a[100000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=a[n]-a[n-1];
    if(s==a[n-1]-a[n-2]&&s==a[n-2]-a[n-3]){
        for(int i=1;i<=n;i++){
            cob+=i*s;
            if(cob==m){
                cout<<i+1;
                return 0;
            }
            if(cob>m){
                cout<<i;
                return 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        m-=a[i]-a[i-1];
        ans++;
        if(m<=0){
            break;
        }
    }
    cout<<ans;
    return 0;
}
