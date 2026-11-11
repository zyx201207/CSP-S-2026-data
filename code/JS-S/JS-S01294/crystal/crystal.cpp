#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],s[500010];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
bool check(int len){
    for(int i=1; i<=n-len+1; i++){
        if(a[i+len-1]*len-(s[i+len-1]-s[i-1])<=m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl;
    return 0;
}