#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long m;
const int MAXN = 5e5+5;
long long a[MAXN];
int ans = 0;
bool check_B(){
    long long diff = a[2]-a[1];
    //cout<<diff<<" ";
    for(int i = 3;i<=n;i++){
        long long cur = a[i]-a[i-1];
        //cout<<cur<<" ";
        if(cur!=diff) return 0;
    }
    return 1;
}
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    //cout<<endl;
    //cout<<check_B()<<endl;
    if(check_B()){
        long long diff = a[2]-a[1];
        long long cnt_diff = 0;
        for(int i =1;i<=n;i++){
            cnt_diff+=i;
            if(cnt_diff*diff <=m ){
                ans = i;
            }
        }
        cout<<min(ans+1,n);
        return 0;
    }
    for(int i = 1;i<=n;i++){
        int cur = 0;
        long long rest = m;
        for(int j = i-1;j>=1;j--){
            if(a[i]-a[j]<=rest){
                rest-=(a[i]-a[j]);
                cur++;
            }
            else{
                break;
            }
        }
        for(int j = i;j<=n;j++){
            if(a[i]==a[j]) cur++;
        }
        ans = max(ans,cur);
    }
    cout<<ans;
}
//14:54 45pts
//try to 75pts
//15:11 maybe 75pts
//go!
