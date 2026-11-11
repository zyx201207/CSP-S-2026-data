#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rint register int
inline int read(){
    rint s=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
inline void print(rint x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int n,m,a[500005],s[500005],res;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(rint i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(rint i=1,j=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        while(j<=i&&(i-j+1)*a[i]-(s[i]-s[j-1])>m)j++;
        res=max(res,i-j+1);
    }
    print(res);
    return 0;
}