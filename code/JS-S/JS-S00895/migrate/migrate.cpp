#include<bits/stdc++.h>
using namespace std;
#define reg register
#define dmemset(a,val) memset(a,val,sizeof(a))
#define putc(c) putchar(c)
#define getc(c) getchar(c)
typedef long long lli;
typedef unsigned long long ull;
inline int read(){
    reg int x=0;
    reg bool isF=0;
    reg char c=getc();
    while(c<'0'||c>'9'){
        isF=(c=='-');
        c=getc();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getc();
    }
    return isF?-x:x;
}
inline lli llread(){
    reg lli x=0;
    reg bool isF=0;
    reg char c=getc();
    while(c<'0'||c>'9'){
        isF=(c=='-');
        c=getc();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1LL)+(x<<3LL)+(c^48);
        c=getc();
    }
    return isF?-x:x;
}
inline void write(reg int x){
    if(x==-2147483648){
        putc('-'),putc('2'),putc('1'),putc('4'),putc('7'),putc('4'),putc('8'),putc('3'),putc('6'),putc('4'),putc('8');
        return;
    }
    if(x<0){
        putc('-');
        x=-x;
    }
    static char i32_out[15];
    reg int top=0;
    do{
        i32_out[++top]=(x%10)^48;
        x/=10;
    }while(x);
    while(top){
        putc(i32_out[top--]);
    }
}
inline void llwrite(reg lli x){
    if(x==LLONG_MIN){
        putc('-'),putc('9'),putc('2'),putc('2'),putc('3'),putc('3'),putc('7'),putc('2'),putc('0'),putc('3'),putc('6'),putc('8'),putc('5'),putc('4'),putc('7'),
        putc('7'),putc('5'),putc('8'),putc('0'),putc('8');
        return;
    }
    if(x<0){
        putc('-');
        x=-x;
    }
    static char i64_out[25];
    reg int top=0;
    do{
        i64_out[++top]=(x%10)^48;
        x/=10;
    }while(x);
    while(top){
        putc(i64_out[top--]);
    }
}
int c,n;
lli d,a[2000005],ans;
vector<pair<int,int>> vec;
set<pair<int,int>> se;
int dp[2000005][2],dp2[2000005][2];
int get_cnt(reg int dian,reg bool flg){
    if(dian<1){
        return 0;
    }
    if(dp[dian][flg]!=-1){
        return dp[dian][flg];
    }
    if(flg){
        reg int l=lower_bound(a+1,a+n+1,a[dian]-d)-a,r=(int)(lower_bound(a+1,a+n+1,a[dian+1]-d)-a-1);
        if(l==r){
            return dp[dian][flg]=(get_cnt(l,0)+1);
        }else if(l<r){
            return dp[dian][flg]=(get_cnt(l,1)+r-l+1);
        }
        return dp[dian][flg]=0;
    }else{
        reg int l=lower_bound(a+1,a+n+1,a[dian]-d)-a;
        if(l<dian){
            return dp[dian][flg]=(get_cnt(l,1)+dian-l);
        }
        return dp[dian][flg]=0;
    }
}
int get_cnt2(reg int dian,reg bool flg){
    if(dian>n){
        return 0;
    }
    if(dp2[dian][flg]!=-1){
        return dp2[dian][flg];
    }
    if(flg){
        reg int l=(int)(upper_bound(a+1,a+n+1,a[dian]+d)-a-1),r=upper_bound(a+1,a+n+1,a[dian-1]+d)-a;
        if(l==r){
            return dp2[dian][flg]=(get_cnt2(r,0)+1);
        }else if(l<r){
            return dp2[dian][flg]=(get_cnt2(r,1)+r-l+1);
        }
        return dp2[dian][flg]=0;
    }else{
        reg int r=upper_bound(a+1,a+n+1,a[dian]+d)-a-1;
        if(r>dian){
            return dp2[dian][flg]=(get_cnt2(r,1)+r-dian);
        }
        return dp2[dian][flg]=0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    reg int T=read();
    while(T--){
        n=read();
        d=llread();
        if(c==13||c==14){
            putc('0');
            putc('\n');
            continue;
        }
        ans=0;
        dp[0][0]=dp[0][1]=dp[n+1][0]=dp[n+1][1]=-1;
        dp2[0][0]=dp2[0][1]=dp2[n+1][0]=dp2[n+1][1]=-1;
        for(reg int i=1;i<=n;i++){
            a[i]=llread();
            dp[i][0]=dp[i][1]=-1;
            dp2[i][0]=dp2[i][1]=-1;
//            pre[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
//            cnt1[i]=i-pre[i];
//            if(cnt1[i]){
//                reg int l1=lower_bound(a+1,a+i+1,a[pre[i]]-d)-a,
//                l2=lower_bound(a+1,a+i+1,a[pre[i]+1]-d)-a;
//                reg int r=min(l2-1LL,pre[i]-1);
//                if(l1<=r){
//                    for(reg int j=l1;j<=r;j++){
//
//                    }
//                }
//            }
        }
//        for(reg int i=n;i;--i){
//            suf[i]=upper_bound(a+1,a+n+1,a[i]+d)-a;
//        }
        vec.clear();
        se.clear();
        a[n+1]=9e18;
        a[0]=-9e18;
        for(reg int i=2;i<n-1;i++){
            reg int l=lower_bound(a+1,a+n+1,a[i+1]-d)-a,
            r=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            if(l<i&&i+1<r){
                reg int lr=lower_bound(a+1,a+n+1,a[i+2]-d)-a-1,
                rl=upper_bound(a+1,a+n+1,a[i-1]+d)-a;
                if(lr<i&&i+1<rl){
                    //cout<<l<<" "<<lr<<" "<<rl<<" "<<r<<"\n";
                    ans+=(lr-l+1LL)*(r-rl+1LL);
//                    for(reg int j=l;j<=lr;j++){
//                        for(reg int k=rl;k<=r;k++){
//                            vec.emplace_back(j,k);
//                            se.emplace(j,k);
//                        }
//                    }
                }
            }
        }
        llwrite(ans);
        putc('\n');
//        for(reg int i=1;i<=n;i++){
//            cout<<get_cnt(i,0)<<" ";
//        }
//        cout<<"\n\n";
        //cout<<"siz:"<<vec.size()<<","<<se.size()<<"\n";
//        for(const auto&val:vec){
//            cout<<"("<<val.first<<","<<val.second<<") ";
//        }
//        cout<<"\n";
    }
    return 0;
}
