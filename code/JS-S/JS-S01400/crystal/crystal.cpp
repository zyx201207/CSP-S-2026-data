#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010;
ll n,m,a[N],ans;
int main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
            cin >> a[i];
    }
    sort(a+1,a+1+n);
    ll i=1,j=1,res=m,cnt=1;
    while(res>=0&&j<=n){
        res-=cnt*(a[j+1]-a[j]);
        j++;
        cnt++;
    }
    if(j>n){
        cout << n;
        return 0;
    }
    j--;cnt--;
    res+=cnt*(a[j+1]-a[j]);
    ans=cnt;
    while(j<=n){
        if(i==j){
            i++,j++;
        }else{
            res+=(a[j]-a[i]);
            i++;
            cnt--;
        }

        while(res>=0&&j<=n){
            res-=cnt*(a[j+1]-a[j]);
            j++;
            cnt++;
        }
        if(j>n){
            ans=max(ans,n-i+1);
            break;
        }
        j--;cnt--;
        res+=cnt*(a[j+1]-a[j]);
        ans=max(ans,cnt);
        //cout << cnt << ":" << i << j << endl;
    }
    cout << ans;
    return 0;
}
