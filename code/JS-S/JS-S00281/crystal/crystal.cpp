#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define int __int128
using namespace std;
signed n;
int m;
int a[500050],sum[500050];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){
        write(x/10);
        x%=10;
    }
    putchar(x+'0');
}
bool check(signed len){
    int mindis=1e20;
    for(signed i=1;i+len-1<=n;i++){
        signed j=i+len-1;
        int nowdis=a[j]*len-sum[j]+sum[i-1];
        mindis=min(mindis,nowdis);
    }
    if(mindis<=m)return 1;
    else return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(signed i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(signed i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    signed l=1,r=n;
    while(l<r){
        signed mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    write(l);
    return 0;
}
