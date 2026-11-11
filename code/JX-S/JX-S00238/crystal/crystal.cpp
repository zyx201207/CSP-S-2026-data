#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int tmplast,tmpin,n,cnt,ans=0,tmp=0;
long a[N];
long long m=0,sum=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>0;i--) a[i]=a[i]-a[i-1];
    if(m>1e8+5){
        tmp=1,sum=m;
        for(int i=1;i<=n-1;i++){
            sum-=(1+i)*i/2*(a[1]-a[0]);
            if(sum<0) break;
            tmp+=1;
        }
        cout<<tmp;
        return 0;
    }
    for(int aim=n-1;aim>=0;aim--){
        int r=aim,l=0,mid;
        while(l!=r){
            mid=(l+r)/2;
            cnt=1,tmp=1,sum=m;
            for(int st=mid+1;st<=aim;st++){
                sum-=cnt*a[st];
                cnt++;
                if(sum<0){
                    tmp=-1;
                    break;
                }
                tmp++;
            }
            ans=max(ans,tmp);
            if(tmp==-1){
                l=mid+1;
            }
            else r=mid;
        }

    }

    cout<<ans;
    return 0;
}
