#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int a[N];
ll q_rd(){
    char c;
    ll res=0,f=1;
    c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        res=(res<<3)+(res<<1)+c-48;
        c=getchar();
    }
    return f*res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n=q_rd(),m=q_rd();
    for(int i=1;i<=n;i++)a[i]=q_rd();
    sort(a+1,a+1+n);
    a[n+1]=a[n];
    ll rem=m;
    int res=2,pos=n,ans=0;
    for(int i=n;i>=1;i--){
        res--;
        rem+=res*(a[i+1]-a[i]);
        while(pos-1>=1&&rem-(a[i]-a[pos-1])>=0)rem-=a[i]-a[--pos],res++;
        //printf("%d %d %lld\n",rem,pos,res);
        ans=max(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}
