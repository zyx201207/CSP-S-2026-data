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
int n;
lli m,a[500005],sum[500005];
void gen(){
    mt19937_64 mt(random_device{}());
    n=mt()%1000+1;
    m=mt()%10000000000000LL+1;
    for(reg int i=1;i<=n;i++){
        a[i]=(mt()-mt())%1000000000000LL;
    }
}
int test1(){
    sort(a+1,a+n+1);
    reg int ans=1;
    for(reg int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(reg int i=1,j;i<=n;i++){
        reg lli he=0;
        for(j=i-1;j;--j){
            he+=a[i]-a[j];
            if(he>m){
                break;
            }
        }
        ans=max(ans,i-j);
    }
    return ans;
}
int solve(){
    sort(a+1,a+n+1);
    reg int ans=1;
    for(reg int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(reg int i=1,j;i<=n;i++){
        reg int l=0,r=i-1,mid;
        while(l<=r){
            mid=l+r>>1;
            if(a[i]*(i-mid)-(sum[i]-sum[mid])<=m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l);
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
//    for(reg int i=1;i<=10000;i++){
//        gen();
//        if(i==1){
//            cout<<n<<"\n";
//            cout<<m<<"\n";
//            for(reg int i=1;i<=min(10,n);i++){
//                cout<<a[i]<<" ";
//            }
//            cout<<"\n";
//        }
//        reg int x,y;
//        x=test1();
//        y=solve();
//        if(i==1){
//            cout<<x<<"\n";
//        }
//        if(x!=y){
//            cout<<"WAAAAAAA\n";
//            break;
//        }
//    }
//    cout<<"ed\n";
    n=read();
    m=llread();
    for(reg int i=1;i<=n;i++){
        a[i]=llread();
    }
    write(solve());
    return 0;
}
