#include<bits/stdc++.h>
using namespace std;
#define MAXN 4000007
#define INF 1e18+7
long long C,T,n,d,a[MAXN],dp[MAXN],f[MAXN],v[MAXN],topn,ans,idx,cnt,s,t,cnt2;
long long lowfind(long long x){
    long long l=0,r=n-1,mid=0,rt=-1;
    while(l<=r){
        mid=l+r>>1;
        if(a[mid]<=x)rt=mid,l=mid+1;
        else r=mid-1;
    }
    return rt;
}
long long highfind(long long x){
    long long l=0,r=n-1,mid=0,rt=-1;
    while(l<=r){
        mid=l+r>>1;
        if(a[mid]>=x)rt=mid,r=mid-1;
        else l=mid+1;
    }
    return rt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=0;i<n;i++)cin>>a[i];
        //cout<<"_______________________________________\n";
        if(C<=10){
            ans=0;
            for(int i=0;i<n;i++){
                //cout<<"i:"<<i<<endl;
                //cout<<"ai:"<<a[i]<<endl;
                for(int j=i;j<n;j++)dp[j]=INF,f[i]=0;
                idx=i;topn=0,cnt=0;
                while(idx<n){
                    v[topn++]=idx;
                    //cout<<"idx:"<<idx<<endl;
                    if(idx==lowfind(a[idx]+d))break;
                    idx=lowfind(a[idx]+d);
                    //cout<<"newidx:"<<idx<<endl;
                }
                cnt2=0;
                for(int j=i;j<n;j++){
                    dp[j]=cnt2,f[j]=1;
                    if(j>=v[cnt2])cnt2++;
                    if(cnt2>=topn)break;
                }
                if(topn<=2)continue;
                cnt2=2;
                for(int j=v[1]+1;j<n;j++){
                    s=highfind(a[j]-d),t=v[cnt2-1];
                    f[j]=f[s];
                    //cout<<j<<' '<<s<<' '<<t<<endl;
                    if(t-s>1)f[j]=3;
                    if(t-s==1){
                        if(f[v[cnt2-2]]==1&&f[t]==1)f[j]=2;
                        else f[j]=3;
                    }
                    if(f[j]==2)ans++;
                    //cout<<"ans:"<<ans<<endl;
                    if(j>=v[cnt2])cnt2++;
                    if(cnt2>=topn)break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
