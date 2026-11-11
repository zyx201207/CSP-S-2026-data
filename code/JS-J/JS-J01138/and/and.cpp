#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==m){
        long long cnt=v[0];
        for(long long i=1;i<n;i++){
            cnt&=v[i];
        }
        cout<<cnt<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    long long ans=0;
    for(long long i=n-m;i>=0;i--){
        vector<long long> dp(m,0);
        dp[0]=v[i];
        for(long long j=i+1;j<n;j++){
            for(long long k=m-1;k>0;k--){
                dp[k]=max(dp[k],dp[k-1]&v[j]);
            }
        }
        ans=max(ans,dp[m-1]);
        if(ans>=v[i-1])break;
    }
    cout<<ans<<endl;
    return 0;
}
/*
wo shi yyf
wo shi jing lin zhong xue (he xi fen xiao) de
wo shi 7(10)
wo shi 26 hao
wo luogu shi tomyyf
wo bilibili shi tomyyf
wo acgo shi tomyyf
wo atcoder shi tomyyf
wo codeforces shi tomyyf
wo qq shi 3789653908
wo shi qu
wo shi ju ruo
wo yi can gang
wo florr shi tomyyff
wo shi zhong guo de
wo shi jiang su de
wo shi nan jing de
wo shi jian ye qu de
wo sheng ri shi 2.19
wo de lao shi :yy,zjq,yk,cxx,wx,sy,sxf,lc,lc
wo de tong xue li you:
    jst,zjy 99
    jst,czh 99
    lsz,xq 99
    zyl,htr 99
    ysx,gky 99
    ljx,zjx 99
    mei you ren he wo 99,hahaha
wo shi sha bi
wo shi shao fu rui
wo shi da sha bi
wo shi nao can
wo shi cai ji
wo shi fei wu
wo lan di san ti zhengjie dou xiang bu chu lai;
wuuuuuuuuuuuuuuuu..(crying)
dan bao li+you hua da gai ke yi na 55 fen
*/
