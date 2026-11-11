#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long a[N];
long long ans=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m+n-1;i++){
        long long sum=a[i];
        for(int j=i;j<=i+m-1;j++) sum&=a[j];
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
