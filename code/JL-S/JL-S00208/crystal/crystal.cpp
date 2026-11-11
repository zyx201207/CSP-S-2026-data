#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
inline LL read(){
    LL num=0,sign=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
        sign=ch=='-' ? -1:1,ch=getchar();
    while(ch>='0' && ch<='9')
        num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return sign>0 ? num:-num;
}
LL n,m,a[N],def[N],pfx1[N],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        def[i]=a[i]-a[i-1];
        pfx1[i]=def[i]*(i-1)+pfx1[i-1];
    }
    LL l=1,r=n;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(pfx1[mid]<m) l=mid;
        if(pfx1[mid]>m) r=mid+1;
        if((pfx1[mid]==m || pfx1[mid]<m && pfx1[mid+1]>m) && pfx1[mid]==pfx1[mid+1])
            l=mid;
        if((pfx1[mid]==m || pfx1[mid]<m && pfx1[mid+1]>m) && pfx1[mid]!=pfx1[mid+1]){
            cnt=mid;
            break;
        }

    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
