#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum,cnt,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=0;
    while(true){
        r++,cnt++;
        sum+=a[r];
        if(r>n)break;
        while(a[r]*cnt-sum>m&&l<r){
            cnt--;
            sum-=a[l++];
        }
        ans=max(ans,cnt);
    }
    cout << ans;
    return 0;
}
