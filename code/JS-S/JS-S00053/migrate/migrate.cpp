#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
long long cnt[N],cnt2[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cnt[i]=0;
            cnt2[i]=0;
            cin>>a[i];
        }
        int l=1;
        for(int r=1;r<=n;r++){
            while(l<r&&a[r]-a[l]>d){
                cnt[l]=r-1-l;
                l++;
            }
            cnt2[r]=r-l;
        }
        while(l<n){
            cnt[l]=n-l;
            l++;
        }
        long long sum=0;
        for(int i=2;i+1<=n-1;i++){
            if((cnt[i]-cnt[i-1]+1)>0&&(cnt2[i+1]-cnt2[i+2]+1)>0)sum+=(cnt[i]-cnt[i-1]+1)*(cnt2[i+1]-cnt2[i+2]+1);
        }
        cout<<sum<<endl;
    }
    return 0;
}
