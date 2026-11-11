#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],l[10000000],m;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int sum=a[1];
    for(int i=2;i<=m;i++){
        sum=a[i]&sum;
    }
    cout<<sum;
    return 0;
}
