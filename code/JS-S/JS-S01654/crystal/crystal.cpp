#include<bits/stdc++.h>
#define int long long
//zhegehuisimaQAQ
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int a[500001],s[500001],n,m,mid;
bool check(){
//    cout<<mid<<":\n";
    if(mid==1) return 1;
    int sum,x,ans=0,l,r;
    for(int i=mid;i<=n;i++){
//        cout<<i<<")\n"<<s[i]<<" "<<s[i-mid]<<"\n";
        sum=s[i]-s[i-mid];sum=sum/mid;
        l=i-mid+1;r=i;
        x=(l+r)>>1;
        if(a[x]>=sum) x--;
//        cout<<sum<<" "<<x<<'\n';
        ans=(x-l+1)*sum-(s[x]-s[l-1]);
//        cout<<ans<<" "<<s[r]-s[x]-(r-x)*sum<<'\n';
        ans+=s[r]-s[x]-(r-x)*sum;
        if(ans<=m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
    int l=1,r=n;
    while(l<=r){
        mid=(l+r)>>1;
        if(check()) l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
    return 0;
}
//wobuxingle
//xieyigeduoxiaoshibuzhidaozaixiesheme
//yijiulaibujixiehoumain
//orz
//RP++ RP++ RP++