#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mxa;
void solve1(){

}
void solve2(){
    cout<<mxa;
}
void solve3(){
    int ans=a[1];
    for(int i=1;i<=n;i++){
        ans&=a[i];
    }
    cout<<ans;
}
void solve4(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
}
void solve5(){

}
void solve6(){
    int cnt[4]={0,0,0,0};
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
    }
    m-=cnt[3];
    if(m<=0){
        cout<<3;
        return;
    }
    if(cnt[2]>=m){
        cout<<2;
        return;
    }
    if(cnt[1]>=m){
        cout<<1;
        return;
    }
    cout<<0;
}
void solve7(){
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mxa=max(mxa,a[i]);
    }
    if(n<=2000){
        if(m==1){
            solve2();
        }
        else if(m==n){
            solve3();
        }
        else{
            solve4();
        }
    }
    else{
        if(m==n-1){
            solve5();
        }
        else if(mxa<4){
            solve6();
        }
        else{
            solve7();
        }
    }
    return 0;
}
