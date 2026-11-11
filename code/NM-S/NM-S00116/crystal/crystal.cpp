#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,p,hqr;
long long m;
long long cost,cnt;
long long a[500005],c[500005],co[500005];
bool flag;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i==2) p=a[i]-a[i-1];
        if(i>1&&a[i]-a[i-1]!=p) flag=1;
    }
    if(!flag){
        if(n%2==1){
            for(int i=1;i<=n/2;++i){
                cost+=p*i;
                if(cost<=m) hqr++;
                else break;
                cost+=p*i;
                if(cost<=m) hqr++;
                else break;
            }
            cout<<hqr+1;
        }
        else{
            for(int i=1;i<=n/2-1;++i){
                cost+=p*i;
                if(cost<=m) hqr++;
                else break;
                cost+=p*i;
                if(cost<=m) hqr++;
                else break;
            }
            if(cost+p*(n/2)<=m) hqr++;
            cout<<hqr+1;
        }
    }
    else{
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(i>1) c[i-1]=a[i]-a[i-1];
    }
    for(int i=n;i>=1;--i){
        cnt=0,k=0;
        memset(co,0,sizeof(co));
        co[i-1]=c[i-1];
        co[i]=c[i];
        for(int j=i;j>2;j--){
            if(j-2>0) co[j-2]=co[j-1]+c[j-2];
        }
        for(int j=i;j<n-1;++j){
            co[j+1]=co[j]+c[j+1];
        }
        sort(co+1,co+n);
        for(int i=1;i<=n-1;++i){
            cnt+=co[i];
            if(cnt<=m) k++;
            else break;
        }
        ans=max(ans,k+1);
    }
    cout<<ans;
    }
    return 0;
}
