#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
int n,m;
inline int read(){
    char ch=getchar();int f=1,k=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){k=(k<<1)+(k<<3)+ch-'0';ch=getchar();}
    return k*f;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    int a[n],b[n];
    rep(i,0,n)a[i]=read();
    sort(a,a+n);
    b[0]=0;
    int v=1,mx=1;
    rep(i,1,n){
        b[i]=(a[i]-a[i-1])*v+b[i-1];
        if(b[i]<=m)mx=max(mx,v+1);
        else {
            b[i]-=a[i]-a[i-v];
            v--;
        }
        v++;
    }
    cout<<mx;
}
