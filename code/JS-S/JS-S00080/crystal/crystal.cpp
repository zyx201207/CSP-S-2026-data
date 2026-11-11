#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,m,a[N],ans,mx;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)mx+=a[n]-a[i];
    if(m>=mx){
        cout<<n<<endl;
    }else{
        for(int i=n;i>=1;i--){
            long long sum=1,k=m;
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]<=k)sum++,k-=a[i]-a[j];
                else break;
            }
            ans=max(sum,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
