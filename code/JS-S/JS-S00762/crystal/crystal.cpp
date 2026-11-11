#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a;
    for (long long i=0;i<n;i++){
        long long b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    long long cnt=0,ans=0;
    for (long long i=n-1,j=n-1;i>=0;i--){
        bool flag=1;
        for (j--;j>=0;j--){
            cnt+=a[i]-a[j];
            if (cnt>m){
                ans=max(ans,i-j);
                cnt-=(a[i]-a[i-1])*(i-j);
                flag=0;
                break;
            }
        }
        if (flag){
            cout<<i+1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
