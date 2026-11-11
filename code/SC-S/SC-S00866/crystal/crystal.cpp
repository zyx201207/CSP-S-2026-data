#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

typedef long long ll;

const int N=5e5+10;

int n;
ll m;
struct Node{
    ll x;
    int c;
}a[N];
int s[N];
ll s2[N];

ll calc(int l,int r){
    return a[r].x*(s[r]-s[l-1])-s2[r]+s2[l-1];
}
int main(){
    Fre("crystal");
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i].x),a[i].c=1;
    sort(a+1,a+n+1,[](Node &a,Node &b){return a.x<b.x;});
    int t=0;
    for(int i=1;i<=n;++i){
        if(i==1||a[i].x!=a[i-1].x) a[++t]=a[i];
        else ++a[t].c;
    }
    n=t;
    for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i].c,s2[i]=s2[i-1]+a[i].x*a[i].c;
    int res=0;
    for(int i=1,l=1;i<=n;++i){
        while(l<i&&calc(l+1,i)>=m) ++l;
        if(l<i) res=max((ll)res,s[i]-s[l]+min((ll)a[l].c,(m-calc(l+1,i))/(a[i].x-a[l].x)));
        else res=max(res,a[i].c);
    }
    printf("%d\n",res);

    return 0;
}