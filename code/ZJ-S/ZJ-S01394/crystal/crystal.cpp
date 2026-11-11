#include<bits/stdc++.h>
#define int long long
//long long 一定不要忘记 %lld
using namespace std;
#define N 500005

inline int read(){int x=0,f=1;char c=getchar();while(!isdigit(c))c-'-'?:(f=-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return f*x;}

int a[N];
int n,m;
bool check(int i,int mid){
    return (a[i]-a[i-1])*(i-mid+1)-(a[i]-a[mid-1])>m;
}


void MAIN(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);

    int ans=0;
    for(int i=1;i<=n;i++){
        // printf("%d: ",i);
        a[i]+=a[i-1];
        int l=1,r=i,mid=l+r>>1;
        for(;l<=r;check(i,mid)?l=mid+1:r=mid-1,mid=l+r>>1);
        // printf("%d ",mid);puts("");
        ans=max(ans,i-l+1);
    }

    printf("%lld",ans);



    return ;
}

signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int Test_time=1;
    while(Test_time--)MAIN();
    return 0;
}
/*

*/
