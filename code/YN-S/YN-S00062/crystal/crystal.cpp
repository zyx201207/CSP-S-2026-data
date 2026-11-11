#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
inline int read(){
    int x=0,f=1;
    char c;
    c=gc();
    while(c<'0'||'9'<c){
        if(c=='-')f=-f;
        if(c==EOF)return 0;
        c=gc();
    }
    if(c==EOF)return 0;
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=gc();
    }
    return f*x;
}
inline void print(int x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x>9)print(x/10);
    pc('0'+x%10);
}
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
int calc(int x){
    int l=1,r=x,res;
    while(l<=r){
        int mid=(l+r)>>1,len=(x-mid+1);
        if(a[x]*len-(sum[x]-sum[mid-1])<=m){
            r=mid-1;
            res=mid;
        }
        else l=mid+1;
    }
    return x-res+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)ans=max(ans,calc(i));
    print(ans);
    return 0;
}
