#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[100005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n<<" "<<m<<"\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    sort(a+1,a+n+1);
    long long ans=1;
    long long ans1=0,k=m;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            k-=a[i]-a[j];
            ans1++;
            if(k<=0) break;
        }
        ans=max(ans,ans1);
        k=m,ans1=0;
    }
    cout<<ans;
    return 0;
}
