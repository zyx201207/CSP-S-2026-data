#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=0;
    sort(a,a+n,greater<int>());
    for(int i=n-1;i>n-1-m;i-=2){
        a[i-2]=a[i]&&a[i-1];
        mx=a[i-2];
    }
    cout<<mx;
    return 0;
}