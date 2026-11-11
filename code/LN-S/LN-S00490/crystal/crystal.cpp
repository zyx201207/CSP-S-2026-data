#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>100){
            flag=0;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int Max=0;
    if(n<=5000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if((i-j+1)*a[i]-sum[i]+sum[j-1]<=m){
                    if(Max<i-j+1){
                        Max=i-j+1;
                    }
                }
            }
        }
        cout << Max;
    }else{
        int i,sum=0,cnt=0;
        for(i=a[2]-a[1];i<=n*(a[2]-a[1])&&sum<=m;i+=a[2]-a[1]){
            sum+=i;
            cnt++;
        }
        cout << cnt;
    }
    return 0;
}
