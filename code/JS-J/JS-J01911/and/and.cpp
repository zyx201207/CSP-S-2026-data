#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    int sum=a[n];
    for(int i=1;i<=m-1;i++){
        sum&=a[n-1];
        n--;
    }
    cout<<sum;
}
