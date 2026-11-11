#include<bits/stdc++.h>
using namespace std;

bool bg_M;
template<typename T>
void read(T &a){
    char c;a=0;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
typedef long long ll;
namespace ZZOI{
int n;ll m;
const int MAXN=1000'010;
ll a[MAXN],s[MAXN];
void main(){
    read(n),read(m);
    for(int i=1;i<=n;++i)read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1,j;i<=n;i=j){
        for(j=i+1;j<=n&&a[i]==a[j];++j);
        int l=1,r=i,mid;
        while(l<r){
            mid=l+r>>1;
            if(a[i]*(j-mid)-(s[j-1]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,j-l);
    }
    printf("%d\n",ans);
}
}
bool ed_M;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)ZZOI::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&bg_M)/1024.0/1024<<" Mb"<<endl;
    return 0;
}