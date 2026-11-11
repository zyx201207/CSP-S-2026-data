#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int a[N],cha,ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n>> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cha=a[2]-a[1];
    sort(a+1,a+n+1);
    if(n%2==1){
        int mid=(1+n)/2,sum=0,sumcha=cha;
        for(int i=mid;i<n;i++){
            sum+=sumcha;
            if(sum>m){
                break;
            }
            ans++;

            sum+=sumcha;
            if(sum>m){
                break;
            }
            ans++;

            sumcha+=cha;
        }
    }else{
        int mid=(1+n)/2,sum=0,sumcha=cha;
        for(int i=mid;i<n-1;i++){
            sum+=sumcha;
            if(sum>m){
                break;
            }
            ans++;

            sum+=sumcha;
            if(sum>m){
                break;
            }
            ans++;

            sumcha+=cha;
        }
        if(sum+sumcha<=m){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
