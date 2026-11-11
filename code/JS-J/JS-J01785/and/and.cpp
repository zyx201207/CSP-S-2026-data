#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long sum[200010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n-m+1;i++){
        sum[i]=a[i];
        for(int j=2;j<=m;j++){
            sum[i]=sum[i]&a[i+j-1];
        }
        if(sum[i]>=a[i+m]){
            cout<<sum[i];
            return 0;
        }
    }
    return 0;
}
