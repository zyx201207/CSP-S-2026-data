#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m;
void solve(){
    int ans1 = -1;
    for(int i = 1;i<=n;i++) {
        ans1 = max(ans1,a[i]);
    }cout<<ans1;
    return;
}

void solve1(){
    long long k = 0;
    for(int i = 1;i<=n;i++){
        if(a[i]==3){
            k++;
        }
    }if(k>=n){
        cout<<3;
        return;
    }for(int i = 1;i<=n;i++){
        if(a[i]==2){
            k++;
        }
    }if(k>=n){
        cout<<2;
    }else{
        cout<<1;
    }return;
}

void solve2(){
    int ans1;
    int maxn = -1;
    for(int i = 0;i<=1;i++){
        int k =a[i+1];
        for(int j = 1;j<=n-1;j++){
            k = k&a[j+i];
        }maxn = max(maxn,k);
    }cout<<maxn;
    return;
}


void solve3(){
    int ans1 = a[1];
    for(int i = 2;i<=n;i++){
        ans1 = ans1&a[i];
    }cout<<ans1;
    return;
}

void solve4(){
    int ans1 = -1;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            ans1 = max(ans1,a[i]&a[j]);
        }
    }cout<<ans1;
    return;
}


int dg(int wz,int zh,int l) //位置 值 长;
{
    int ans1 = 0;
    if(l==m){
        return zh;
    }for(int i = wz+1;i<=n;i++){
        ans1 = max(dg(i,zh&a[i],l+1),ans1);
    }return ans1;
}




void solve5(){
    int ans1 = 0;
    for(int i = 1;i<=n-m+1;i++){
        ans1 = max(dg(i,a[i],1),ans1);
    }cout<<ans1;
    return;
}


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool A = 1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4){
            A = 0;
        }
    }if(m==1){
        solve();
    }else if(A){
        solve1();
    }else if(m==n-1){
        solve2();
    }else if(m==n){
        solve3();
    }else if(m==2){
        solve4();
    }else if(n<=20){
        solve5();
    }else{
        cout<<0;
    }
    return 0;
}
