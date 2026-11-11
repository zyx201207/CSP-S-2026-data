#include<bits/stdc++.h>
using namespace std;
#define N 200010
int bi[N][32];
int a[N];
int n,m;
void sol1(){
    int ans=0;
    for(int i=1;i<=(1<<n);i++){
        int res=-1;
        if(__builtin_popcount(i)!=m)continue;
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))){
                if(res==-1)res=a[j];
                res&=a[j];
            }
        }
        ans=max(ans,res);
    }
    cout<<ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int mx=0,ad=-1,flga=1,flgb=1,flg4=1;
    cin>>n>>m;
    if((1<<__builtin_popcount(n-1))!=n)flgb=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        ad=(ad==-1?a[i]:ad&a[i]);
        if(a[i]>=4)flg4=0;
        if((1<<__builtin_popcount(a[i]))!=a[i]+1)flga=0;
        if(a[i]!=i-1)flgb=0;
    }
    if(n<=20){
        sol1();
        return 0;
    }
    if(m==1){
        cout<<mx;return 0;
    }
    if(m==n){
        cout<<ad;return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(flg4){
        int ans=-1;
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=m;i++){
            ans=(ans==-1?a[i]:ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(flga){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];return 0;
    }
    if(flgb){
        cout<<n-m;return 0;
    }
    cout<<0;
    
}

// wo qu CCF tai NB le, qu nian chu xor jin 
// nian zen me jiu chu le and, bu guo mei 
// you guan xi, zhe wu yi shi geng jian dan 
// de.

// wo qu wo mei you xiang chu lai, wo wu
// yi shi fen nu de.
// suo yi wo jue ding kai shi na bu fen fen.

// OK a. zhi jie shi yong 65 pts de bu fen 
// fen.

// xian zai kai T4.