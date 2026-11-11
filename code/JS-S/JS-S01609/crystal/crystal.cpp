#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005];
bool vis=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long v=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            v=a[i]-a[i-1];
        }
        if(i>1){
            long long y=a[i]-a[i-1];
            if(v!=y){
                vis=1;
            }
        }
    }
    if(!vis){
        long long num=0,cnt=1;
        if(a[n]>a[1]){
            for(int i=n-1;i>=1;i--){
                if(num+a[n]-a[i]<=m){
                    cnt++;
                    num+=a[n]-a[i];
                }else{
                    ans=max(ans,cnt);
                    break;
                }
            }
        }else{
            for(int i=2;i<=n;i++){
                if(num+a[1]-a[i]<=m){
                    cnt++;
                    num+=a[1]-a[i];
                }else{
                    ans=max(ans,cnt);
                    break;
                }
            }
        }
         cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long num=0,cnt=1;
        bool x=0,y=0;
        for(int j=i+1,k=i-1;j<=n||k>=1;){
            if(j>n+1){j--;}
            if(k<0){k++;}
            long long x1=1e18,x2=1e18;
            if(a[j]<=a[i]&&!x&&j<=n){
                x1=a[i]-a[j];
            }else{
                x=1;
            }
            if(a[k]<=a[i]&&!y&&k>=1){
                x2=a[i]-a[k];
            }else{
                y=1;
            }
            if(x&&y){
                break;
            }
            long long minn=min(x1,x2);
            if(num+minn<=m){
                cnt++;
                num+=minn;
                if(minn==x1){
                    j++;
                }else{
                    k--;
                }
            }else{
                break;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
