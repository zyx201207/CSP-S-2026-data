#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,a[200005]={0},m,num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    num=a[n];
    for(int i=n;i>n-m;i--){
        num=num and a[i-1];
    }
    cout<<num;
    return 0;
}
