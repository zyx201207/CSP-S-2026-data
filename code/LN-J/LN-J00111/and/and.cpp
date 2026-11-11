#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(long long b,long long c){
    return b>c;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m+1,cmp);
    cout<<a[n];
    return 0;
}
