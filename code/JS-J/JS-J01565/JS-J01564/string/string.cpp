#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x<10){putchar(x+48);return;}
    else{write(x/10);putchar(x%10+48);}
}
const int N=2e5+10;
char c[N];int a[N],d[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;n=read();
    int cnt0=0;
    for(int i=1;i<=n;i++){
        a[i]=read();cin>>c[i];
        d[i]=d[i-1]+a[i];cnt0+=a[i];
    }
    int li=1,ri=n,l=1,r=cnt0,ans=0;
    while(li!=ri){
        if(d[li]-l+1<r-d[ri-1]){
            if(c[li]!=c[ri]) ans+=d[li]-l+1;
            r-=d[li]-l+1;l=d[li]+1;li++;
        }
        else{
            if(c[li]!=c[ri]) ans+=r-d[ri-1];
            l+=r-d[ri-1];r=d[ri-1];ri--;
        }
    }
    write(ans);
    return 0;
}