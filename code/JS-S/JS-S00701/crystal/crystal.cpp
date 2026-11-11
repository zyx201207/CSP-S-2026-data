#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,x[500005],k,ans;
struct node{ll num,x;}a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    ll dengchazhi;
    bool f=1;

    for(int i=1;i<=n;++i){
        scanf("%lld",&x[i]);
        if(i>1 && abs(x[i]-x[i-1])!=dengchazhi)f=0;
        dengchazhi=abs(x[i]-x[i-1]);
    }

    if(f){
        ll c=0,sum=0,d=abs(x[1]-x[2]);
        while(sum<=m)c+=d,sum+=c;
        printf("%lld",c);
        return 0;
    }

    sort(x+1,x+n+1,[](int i,int j){return i<j;});
    int sum=1;
    for(int i=1;i<=n;++i)
        if(x[i]!=x[i-1])a[++k]={sum,x[i-1]},sum=1;
        else ++sum;
    for(int i=1;i<=k;++i){
        ll num=a[i].num,x=a[i].x,sum=0,cnt=num;
        for(int j=i-1;j>=1 && sum<=m;--j){
            ll need=x-a[j].x,add=min(a[j].num,(m-sum)/need);
            cnt+=add,sum+=add*need;
            if(sum<need)break;
        }
        ans=max(ans,cnt);
    }
    printf("%lld",ans);
    return 0;
}
