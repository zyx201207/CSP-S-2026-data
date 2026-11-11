#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[555555],p[555555];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    memset(p,sizeof(p),0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        p[i]=a[i]-a[i-1];
    }
    long long sum=2,cnt=1,ans=-1;
    bool f=false;
    for(int i=2;i<=n;i++){
        while(m-p[i]*cnt<0&&cnt!=1){
            ans=max(ans,cnt);
            m+=p[sum]*(cnt-1);
            cnt-=1;
            sum+=1;
            f=true;
        }
        if(m-p[i]*cnt>=0&&f==false){
            m-=p[i]*cnt;
            cnt++;
        }
    }
    ans=max(ans,cnt);
    cout<<ans;
    return 0;
}
