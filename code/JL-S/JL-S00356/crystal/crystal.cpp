#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
int n,pos;
ll m,a[N],q[N];
inline bool check(int cnt){
    int h=1,t=0;
    for(int i=1;i<=cnt;i++){
		q[++t]=a[i];
		//printf("%lld\n",a[i]);
	}
    ll cur=0,lst=q[t];
    //printf("%lld\n",lst);
    for(int i=1;i<cnt;i++) cur=cur+(a[cnt]-a[i]);
    for(int i=cnt+1;i<=n;i++){
        if(cur<=m) return 1;
        ll temp=q[h++];
        cur=cur-lst+temp+(cnt-1)*(a[i]-lst);
        lst=a[i],q[++t]=lst;
        //printf("%lld\n",cur);
    }
    return (cur<=m)?1:0;
}
inline void calc(){
    int l=1,r=n,mid;
    while(l<(r-1)){
        mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
        //printf("%d %d\n",l,r);
    }
    printf("%d\n",l);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    //printf("%d\n",n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    calc();
    return 0;
}
