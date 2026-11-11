#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010],cnt[500010],ans=1,far=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (long long i=1;i<=n;i++)
        cin >> a[i];
    sort(a,a+n+1);
    for (long long i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+(i-far)*(a[i]-a[i-1]);
        if(cnt[i]>m){
            if(a[i]-a[i-1]>m){
                cnt[i]=0;
                far=i;
            }else if(a[i]-a[i-1]==m){
                cnt[i]=m;
                far=i-1;
            }else{
                while(cnt[i]>m){
                    cnt[i]-=a[i]-a[far];
                    far++;
                }
            }
        }
        ans=max(ans,i-far+1);
    }
    cout << ans << endl;
    return 0;
}