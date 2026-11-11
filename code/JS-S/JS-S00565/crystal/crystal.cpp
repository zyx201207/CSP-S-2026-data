#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
        cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
for(int i=1;i<=n;i++){
    if(m-i>=0){
        cnt++;
        m-=i;
    }
    else break;
}
if(cnt>=n){
    cnt=n;
}
cout<<cnt;
    return 0;
}
