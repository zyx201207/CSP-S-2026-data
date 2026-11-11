

#include <bits/stdc++.h>
using namespace std;
const int N =2e5+10;
long long n,l,r,lsum,rsum,la[N],ra[N],mid,sum=0,ans=0,cnt;
long long a[N];
char c[N],lc[N],rc[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        sum+=a[i];
    }
    mid = sum>>1;
    l = 0,r = n+1,cnt=0;
    rsum = sum;
    while(1){
        if(lsum+a[l+1] <= mid+1){
            lsum+=a[l+1];
            l++;
            la[l] = a[l];
            lc[l] = c[l];
        }
        else{
        if(rsum-a[r-1] >= mid){
            rsum-=a[r-1];
            r--;
            cnt++;
            ra[cnt] = a[r];
            rc[cnt] = c[r];
        }
        else break;
        }
    }
    //cout << r-l-1 << " " << l << " " << r << " " << a[l] << " " << a[r] << endl;
    if(r-l-1!=0){
        int x = l+1;
        if(sum%2==0){
            la[l+1] = mid-lsum;
            ra[cnt+1] = a[x]-mid+lsum;
            lc[l+1] = rc[cnt+1] = c[x];
        }
        else{
            la[l+1] = mid-lsum;
            ra[cnt+1] = a[x]-mid+lsum-1;
            lc[l+1] = rc[cnt+1] = c[x];
        }
    }
    else{
        if(sum%2!=0){
            if(lsum > sum-lsum){
                a[l]--;
            }
            else a[r]--;
        }
    }
    //cout << r-l-1 << " " << l << " " << r << " " << a[l] << " " << a[r] << endl;
    int cnt1 = 1,cnt2=1;
    while(cnt1 <= l && cnt2 <= cnt){
        if(la[cnt1] < ra[cnt2]){
            if(lc[cnt1] != rc[cnt2]){
                ans+=la[cnt1];
            }
            ra[cnt2]-=la[cnt1];
            cnt1++;
        }
        else if(la[cnt1] > ra[cnt2]){
            if(lc[cnt1] != rc[cnt2]){
                ans+=ra[cnt2];
            }
            la[cnt1]-=ra[cnt2];
            cnt2++;
        }
        else{
            if(lc[cnt1] != rc[cnt2]){
                ans+=ra[cnt2];
            }
            cnt1++;
            cnt2++;
        }
    }
    cout << ans;

    return 0;
}

