#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string s[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n-m+1;i++){
        long long sum=a[i];
        for(int j=i;j<=i+m-1;j++){
            sum=sum&a[j];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
