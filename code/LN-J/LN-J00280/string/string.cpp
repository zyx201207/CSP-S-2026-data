#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200020],p,sum,l[200020],r[200020],k,m,ans;
char c[200020],lc[200020],rc[200020];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int k;
        char x;
        cin>>k>>x;
        sum+=k;
        if(x==c[p]) a[p]+=k;
        else a[++p]=k,c[p]=x;
    }
    int cnt=0,kg=0;
    for(int i=1;i<=p;i++){
        int s=cnt;
        cnt+=a[i];
        if(!kg&&cnt>sum/2){
            if(sum%2==0) l[++k]=sum/2-s,r[++m]=cnt-sum/2,lc[k]=rc[m]=c[i];
            else l[++k]=sum/2-s,r[++m]=cnt-1-sum/2,lc[k]=rc[m]=c[i];
            kg=1;
            continue;
        }
        if(!kg) l[++k]=a[i],lc[i]=c[i];
        else r[++m]=a[i],rc[m]=c[i];
    }
    int i=1,j=m;
    while(i<=k&&j>=1){
        l[i],r[j];
        if(l[i]<r[j]){
            if(lc[i]==rc[j]) r[j]-=l[i];
            else r[j]-=l[i],ans+=l[i];
            i++;
        }
        else if(l[i]>r[j]){
            if(lc[i]==rc[j]) l[i]-=r[j];
            else l[i]-=r[j],ans+=r[j];
            j--;
        }
        else{
            if(lc[i]==rc[j]) l[i]-=r[j];
            else l[i]-=r[j],ans+=r[j];
            i++,j--;
        }
    }
    printf("%lld",ans);
}
