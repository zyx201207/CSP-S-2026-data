#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long sum1=a[n];
    for(int i=n-1;i>n-m;i--){
        sum1=sum1&a[i];
    }
    cout<<sum1;
    return 0;

}
