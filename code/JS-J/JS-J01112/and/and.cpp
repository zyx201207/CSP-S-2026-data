#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005],ans,sum;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    std::stable_sort(a+1,a+n+1);
    for(int i=1;i<=n-m+1;i++){
        sum=a[i];
        for(int j=1;j<m;j++){
            sum=sum&a[i+j];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
