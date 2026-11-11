#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
inline int read(){
    char ch=getchar();int f=1,k=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){k=(k<<1)+(k<<3)+ch-'0';ch=getchar();}
    return k*f;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c=read();
    t=read();
    while(t--){
        int n=read(),d=read();
        rep(i,0,n)int a=read();
        cout<<n/d<<endl;
    }

}
