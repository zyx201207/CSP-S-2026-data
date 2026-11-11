#include <bits/stdc++.h>
using namespace std;
long long n,k,a[2000002],x[2000002],ans=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T,c;
    cin >> c >> T;
    if(c==11 || c==12){
        while(T--){
            cin >> n >> k;
            for(int i=1;i<=n;i++){
                cin >> a[i];
            }
            cout << n-k/(a[2]-a[1])-1 << endl;
        }
        return 0;
    }
    if(c==13 || c==14){
        while(T--){
            ans=0;
            cin >> n >> k;
            for(int i=1;i<=n;i++){
                cin >> a[i];
            }
            for(int l=1,r=1;l<=n;l++){
                while(r<=n&&a[r]-a[l]<=k){
                    x[r]=l;
                    if(r-l>=2)ans+=x[l+2]-x[l+1];
                    r++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
    while(T--){
        ans=0;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n-3;i++){
            if(a[i]+k<a[i+3]&&a[i]+k>=a[i+2]&&a[i+1]+k>=a[i+3]){
                int cnt1=1,cnt2=1,pre0=i+2,pre1=i+3,pre2=-1;
                for(int j=i+4;j<=n;j++){
                    if(a[pre0]+k<a[j]&&a[pre1]+k>=a[j])cnt1++,pre2=j;
                    else if(a[pre1]+k<a[j]){
                        if(pre2==-1)break;
                        pre1=pre2;
                        pre0=pre1-1;
                    }
                }
                pre0=i+1,pre1=i,pre2=-1;
                for(int j=i-1;j<=n;j++){
                    if(a[pre0]-k>a[j]&&a[pre1]-k<=a[j])cnt2++,pre2=j;
                    else if(a[pre1]-k>a[j]){
                        if(pre2==-1)break;
                        pre1=pre2;
                        pre0=pre1+1;
                    }
                }
                ans+=cnt1*cnt2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
