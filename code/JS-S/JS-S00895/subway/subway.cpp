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
int c,n,m,d,Q,t[500005];
vector<int> a[500005];
unordered_map<int,int> path[505];
lli dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    Q=read();
    for(reg int i=1;i<=m;i++){
        t[i]=read();
    }
    dmemset(dis,0x3f);
    for(reg int i=1,maxj;i<=n;i++){
        maxj=read();
        dis[i][i]=0;
        for(reg int j=1,dian,tim;j<=maxj;j++){
            dian=read();
            tim=read();
            path[i][dian]=tim;
            for(const int& val:a[dian]){
                dis[val][i]=dis[i][val]=
                min(dis[i][val],(lli)tim+path[val][dian]);
            }
            a[dian].emplace_back(i);
        }
    }
    for(reg int k=1;k<=n;k++){
        for(reg int i=1;i<=n;i++){
            for(reg int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
//    cout<<"\n\n";
//    for(reg int i=1;i<=n;i++){
//        for(reg int j=1;j<=n;j++){
//            cout<<dis[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n\n";
    for(reg int i=1,x,y;i<=Q;i++){
        x=read();
        y=read();
        reg lli ans=LLONG_MAX;
        for(const int&v1:a[x]){
            for(const int &v2:a[y]){
                ans=min(ans,path[v1][x]+path[v2][y]+dis[v1][v2]);
            }
        }
//        cout<<"ans:"<<ans<<" ";
        llwrite(t[x]+t[y]+ans);
        putc('\n');
    }
    return 0;
}
