#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,a[500001];
int f[500001];
int ans=-1225;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=1;
        long long s=0;
        for(int j=i-1;j>=1;j--){
            s=s+(a[i]-a[j]);
            if(s<=m) f[i]++;
            else break;
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}
