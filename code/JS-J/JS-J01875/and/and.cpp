#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+10;
constexpr int M=N;
int n,m;
int arr[N];
bool check(int p){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if((arr[i]&p)==p){
            cnt++;
        }
    }
    return cnt>=m;
}
int cal_force(int p){
    int res=(1ll<<32ll)-1ll;
    for(int i=1;i<=n;i++){
        if((p>>(i-1ll))&1ll){
            res&=arr[i];
        }
    }return res;
}
void solve_force(){
    int ans=-1e14;
    for(int i=0;i<(1ll<<n);i++){
        int cnt=__builtin_popcountll(i);
        if(cnt!=m) continue;
        ans=max({ans,cal_force(i)});
    }cout<<ans<<'\n';
}
void solve_special(){
    for(int i=(1ll<<10ll);i>=1;i--){
        if(check(i)){
            cout<<i<<'\n';
            return ;
        }
    }cout<<0<<'\n';
}
void solve_m1(){
    cout<<*max_element(arr+1,arr+1+n)<<'\n';
}
void solve_mn(){
    int res=(1ll<<32ll)-1;
    //cerr<<res<<'\n';
    for(int i=1;i<=n;i++){
        res&=arr[i];
    }cout<<res<<'\n';
}
void solve_m2(){
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            res=max({res,(arr[i]&arr[j])});
        }
    }cout<<res<<'\n';
}
bool check_A(){
    for(int i=1;i<=n;i++){
        bool f=false;
        for(int k=0;k<=31;k++){
            if(arr[i]==(1ll<<k)){
                f=true;
                break;
            }
        }
        if(!f) return false;
    }return true;
}
void solve_A(){
    sort(arr+1,arr+1+n,greater<int>());
    cout<<arr[m]<<'\n';
}
void solve_std(){
    int l=0,r=1e14;
    //cerr<<check(11)<<'\n'; exit(0);
    while(l<r){
        int mid=(l+r+1ll)>>2ll;
        if(check(mid)) l=mid;
        else r=mid-1;
    }cout<<l<<'\n';
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    //solve_A(); exit(0);
    if(n<=20){
        solve_force(); //O(2^n)
        return 0;
    }else if(m==1){
        solve_m1(); //O(n);
        return 0;
    }else if(m==n){
        solve_mn(); //O(n);
        return 0;
    }else if(m==2 && n<=2000){
        solve_m2(); //O(n^2)
        return 0;
    }else if(check_A()){
        solve_A(); //O(nlogn)
        return 0;
    }else if(*max_element(arr+1,arr+1+n)<=(1ll<<10ll)){
        solve_special(); //O(nA)
        return 0;
    }else{
        solve_std();
        return 0;
    }
    return 0;
}
/*
RP++
9:08 i think 1= needs 230~260pts
9:13 maybe DP
9:27 not DP
9:40 force first
9:43 now 25pts
9:47 now 35pts
9:48 now 40pts
10:25 no idea
10:33 now 50pts
10:38 now 55pts tot:100+100+55+48=303
10:45 now 70pts,so i got such high points just with solve-force and solve-special AWA
11:26 now 75pts
*/
