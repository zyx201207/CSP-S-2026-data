#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100086]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int x=a[n-1];
    for(int i=n-2;i>=n-3;i--){
        x=(a[i]&x);
    }
    cout<<x;
    return 0;
}
