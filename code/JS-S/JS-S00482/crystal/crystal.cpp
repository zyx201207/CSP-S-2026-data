#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int cha[500005];
int sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int minn=1;
    bool f1=true;
    bool f2=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)f1=false;
        if(i>2){
            if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){
                f2=false;
            }
        }
        minn=min(minn,a[i]);
    }
    if(f1){
        int ans=(sqrt(1+8*m)-1)/2+1;
        cout<<ans;
        return 0;
    }
    if(f2){
        int ans=(sqrt(1+8*m)-1)/2;
        cout<<ans/(a[2]-a[1])+1;
        return 0;
    }
    if(minn<0){
        for(int i=1;i<=n;i++){
            a[i]+=abs(minn)+1;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cha[i]=a[i]-a[i-1];
        sum[i]=cha[i]+sum[i-1];
    }
    int maxx=-1;
    int maxi;
    for(int i=1;i<=n;i++){
        int num=0;
        int ans=0;
        for(int j=i-1;j>=1;j--){
            num+=sum[i]-sum[j];
            if(num<=m){
                ans++;
            }else{
                break;
            }
        }
        if(maxx<ans){
            maxx=ans;
            maxi=i;
        }
    }
    for(int i=a[maxi-1]+1;i<a[maxi];i++){
        int num=0;
        int ans=0;
        for(int j=maxi-1-1;j>=1;j--){
            num+=sum[maxi-1]-sum[j]+(maxi-1)*(i-a[maxi-1]);
            if(num<=m){
                ans++;
            }else{
                break;
            }
        }
        maxx=max(ans,maxx);
    }
    cout<<maxx+1;
}
