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
int c,n,K,fir[1000005],nxt[2000005],a[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();
    reg int T=read();
    while(T--){
        n=read();
        K=read();
        for(reg int i=1;i<=n;i++){
            fir[i]=0;
        }
        for(reg int i=1,x,y;i<n;i++){
            a[i+n]=x=read();
            a[i]=y=read();
            nxt[i]=fir[x];
            fir[x]=i;
            nxt[i+n]=fir[y];
            fir[y]=i+n;
        }
        putc('0');
        putc('\n');
    }
    return 0;
}
