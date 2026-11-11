#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
    return x*f;
}int d1,d2;
long long l,r;
int n;
int a[200010];
char c[200010];
long long len,cnt;
long long zheng[200010],fan[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    zheng[1]=1;
    fan[n]=1;
    for(int i=1; i<=n; i++){
        a[i]=read(),len+=a[i];
        cin>>c[i];
    }
    for(int i=2; i<=n; i++) zheng[i]=zheng[i-1]+a[i-1];
    for(int i=n-1; i>=1; i--) fan[i]=fan[i+1]+a[i+1];
    /*for(int i=1; i<=n; i++) cout<<zheng[i]<<' ';
    cout<<endl;
    for(int i=1; i<=n; i++) cout<<fan[i]<<' ';*/
    l=1,r=1;
    d1=1,d2=n;
    while(l<len+1-r){
        int x=min(zheng[d1+1]-l,fan[d2-1]-r);
        if(c[d1]!=c[d2]) cnt+=x;
        l+=x,r+=x;
        if(l>=zheng[d1+1]) d1++;
        if(r>=fan[d2-1]) d2--;
    }cout<<cnt;
}