#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt=0,mm,f=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mm=m;
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<n;i++){
        mm-=b[i];
        cnt++;
        if(mm<=0){
            break;
        }
    }
    cout<<cnt;
    return 0;
}
