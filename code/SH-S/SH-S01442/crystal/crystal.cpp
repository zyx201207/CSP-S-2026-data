#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n; long long m;
    cin>>n>>m;
    vector<long long> a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long mm=0;
    sort(a.begin()+1,a.end());
    int i=1,j=0;
    int ans=1;
    for(;i<=n;i++){
        mm+=(i-j-1)*(a[i]-a[i-1]);
        while(mm>m){
            j++;mm-=(a[i]-a[j]);
        }
        ans=max(ans,i-j);
    }
    cout<<ans<<endl;
    return 0;
}
