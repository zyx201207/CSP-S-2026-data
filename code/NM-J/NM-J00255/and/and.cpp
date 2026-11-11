#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long a[N];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1,cmp);
    long long cnt=a[1];
    for(int i=1;i<=m;i++){
        cnt=a[i]&cnt;
    }cout<<cnt<<endl;
    return 0;
}
