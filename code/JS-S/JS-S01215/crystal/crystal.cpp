#include <bits/stdc++.h>
using namespace std;
const int N = 6e5+7;
long long num[N],a[N];
long long ans;
int n;
long long m;
int check(long long mid){
    long long mn = 1e18,m1 = m;
    long long idx = -1;
    ans = 0;
    for(int i = 1;i<=n;i++){
        a[i] = mid-num[i];
       // cout<<a[i]<<" ";
        if(a[i]<0) continue;
        if(a[i]<=mn){
            mn = a[i];
            idx = i;
        }
    }
  //  cout<<'\n';
    for(int i = idx;i>=1;i--){
        if(m1-a[i]>=0){
            m1-=a[i];
            ans++;
        }
        else{//zuo yi

            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.ans","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
        num[i]+=1e12;
    }
    long long res = 0;
    sort(num+1,num+n+1);
    long long mx = 1;
    for(int i = 1;i<=n+1;i++){
        if(num[i] == num[i-1]){
            mx++;

        }
        else{
            if(mx>=res){
                res = mx;
                check(num[i-1]);
                res = max(res,ans);
            }
            mx = 1;
        }
    }

    long long l = 0,r =1e18;
    long long mid;
    while(l<=r){
        mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
        res = max(res,ans);
    }
    cout<<res;
}
