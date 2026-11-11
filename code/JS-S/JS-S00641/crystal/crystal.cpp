#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int aa[500010];
int bb[500010];
int cnt[500010];
int sum[500010];
int sumcnt[500010];

signed main(){
    //Oct31==Dec25?
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>aa[i];
    }
    sort(aa+1,aa+n+1);
    bb[1]=aa[1];
    cnt[1]++;
    int cnt2=1;
    for (int i=2;i<=n;i++){
        if (aa[i]!=aa[i-1]){
            cnt2++;
            cnt[cnt2]++;
            bb[cnt2]=aa[i];
        }
        else{
            cnt[cnt2]++;
        }
    }
    for (int i=1;i<=cnt2;i++){
        sumcnt[i]=sumcnt[i-1]+cnt[i];
    }
    
    for (int i=1;i<=cnt2;i++){
        for (int j=i;j<=cnt2;j++){
            //if (sumcnt[j]-sumcnt[i-1]==315275){
                //cout<<sumcnt[j]-sumcnt[i-1]<<endl;
            //}
        }
    }
    
   for (int i=1;i<=cnt2;i++){
       sum[i]=sum[i-1]+bb[i]*cnt[i];
   }
    int ans=1;
    for (int i=2;i<=cnt2;i++){
        int l=1,r=i,mid;
        int currans=1;
        while (l<=r){
            mid=(l+r)/2;
            int curr=(sumcnt[i-1]-sumcnt[mid-1])*bb[i]-(sum[i-1]-sum[mid-1]);

            if (curr<=m){
                r=mid-1;
                currans=max(currans,sumcnt[i]-sumcnt[mid-1]);
            }
            else{
                if ((sumcnt[i-1]-sumcnt[mid])*bb[i]-(sum[i-1]-sum[mid])<=m){
                    int anss=sumcnt[i]-sumcnt[mid];
                    anss+=(m-((sumcnt[i-1]-sumcnt[mid])*bb[i]-(sum[i-1]-sum[mid])))/(bb[i]-bb[mid]);
                    currans=max(currans,anss);
                }
                //if (currans==314080){
                    //cout<<
               // }
                l=mid+1;
            }
        }
        //cout<<currans<<endl;
        ans=max(ans,currans);
        //cout<<ans<<" "<<i<<endl;
    }
    cout<<ans;
    return 0;
}