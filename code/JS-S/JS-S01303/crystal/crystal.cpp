#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+1;
long long a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;long long m;cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);

    long long ans = 0,sum = 0;

    for(long long i = 1;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-1);
        s[i] = sum;
        if(sum<=m) {
            ans = max(ans,i);
        }
        else{
            int l = 1,r = i;
            while(l<=r){
                int mid = l+(r-l)/2;
                int cnt = s[mid]+(a[i]-a[mid])*mid;
                if(cnt>=sum-m){
                    ans = max(ans,i-mid);
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
    }
    cout << ans;
}
