#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+10;
int read(){
    int ret=0,sgn=0,ch=getchar();
    while(ch>'9'||ch<'0'){
        sgn |= ch=='-',ch=getchar();
    }
      while(ch<='9'&&ch>='0'){
        ret=ret*10+ch-'0',ch=getchar();
    }
    return sgn ? -ret:ret;
}
struct node{
    ll a;
    int rk;
}s[MAXN];
int n,m,maxn;
ll ans,base[32];
bool bis[32][MAXN],biss[32];
bool cmp(node x,node y){
    return x.a>y.a;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i].a);
        s[i].rk=i;
    }
    for(int i=1;i<=n;i++){
        ll d=s[i].a;
        int k=0;
        while(d>0){
            bis[k++][i]=d%2;
            d/=2;
        }
        maxn=max(maxn,k-1);
    }
    sort(s+1,s+1+n,cmp);
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<=maxn;j++)cout<<bis[j][s[i].rk];
        cout<<endl;
    }*/
    for(int i=0;i<=maxn;i++)base[i]=1<<i,biss[i]=1;
    for(int j=0;j<=maxn;j++){
        ll cnt=0,sum=0;
        for(int i=1;i<=n;i++){
           if(bis[j][s[i].rk]==0)continue;
           for(int k=0;k<=maxn;k++)biss[k]=biss[k]&&bis[k][s[i].rk];
           sum++;
           if(sum==m)break;
        }
        if(sum==m)
        {
            for(int i=0;i<=maxn;i++)cnt+=biss[i]*base[i],biss[i]=1;
        }
        ans=max(cnt,ans);
        //cout<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}