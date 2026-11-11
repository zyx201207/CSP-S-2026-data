#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+5,M=5e5+5;
inline LL read(){
    LL num=0,sign=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
        sign=ch=='-' ? -1:1,ch=getchar();
    while(ch>='0' && ch<='9')
        num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return sign>0 ? num:-num;
}
LL c,n,t,d,x[M];
pair<LL,LL> at[N][25];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),d=read();
        for(int i=1;i<=n;i++) x[i]=read();
        cout<<n-d-1<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
