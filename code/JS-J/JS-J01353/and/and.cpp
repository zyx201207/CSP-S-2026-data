#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000010];
long long b[2000010];
bool cmp(long long a,long long b){
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
    for(int i=1;i<=n-1;i++){
        b[i]=a[i]&=a[i+1];
    }
    sort(b+1,b+n,cmp);
    cout<<b[m-1];
    return 0;
}
