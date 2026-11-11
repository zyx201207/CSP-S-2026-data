#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int n,m,ma;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    for(int i=2;i<=n;i++){
        int cnt=1,k=m;
        for(int j=i-1;j>=1;j--){
            if(k>=(a[i]-a[j])){
                cnt++;
                k-=(a[i]-a[j]);
            }
            else break;
        }
        ma=max(ma,cnt);
    }
    cout<<ma;
    return 0;
}
