#include <bits/stdc++.h>
using namespace std;
const long long MN=2e6+6,LLM=0x7FFFFFFFFFFFFFFFLL;
long long ps[MN];
long long sdc(long long n,long long d){
    long long gc=ps[1]-ps[0];
    if(gc*2>d) return 0;
    return (n-d/gc*2+1>0)?n-d/gc*2+1:0;
}
long long minc,cnt;
void check(long long x,long long r,long long d,int stp){
    if(x==r){
        if(minc==stp) ++cnt;
         else minc=stp,cnt=1;
        return ;
    }
    if(stp>=minc){
        return ;
    }
    for(int i=x+1;i<=r&&ps[i]-ps[x]<=d;++i){
        check(i,r,d,stp+1);
    }
}
long long s(long long n,long long d){
    long long re=0;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            minc=LLM,cnt=0;
            check(i,j,d,1);
            if(cnt==2&&minc!=LLM){
                ++re;
            } 
        }
    }
    return re;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=0;i<n;++i) cin>>ps[i];
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        long long flg=1,flgx=ps[1]-ps[0];
        for(int i=2;i<n;++i) flg=flg&(ps[i]-ps[i-1]==flgx);
        if(flg){
            cout<<sdc(n,d)<<endl;
            continue;
        }
        cout<<s(n,d)<<endl;
    }
    return 0;
}