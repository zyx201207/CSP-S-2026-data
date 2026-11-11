#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int minn[500005]={0};
    for(int i=1;i<=n;i++) minn[i]=a[i+1]-a[i];
    int k=1,cnt;
    for(int i=1;i<n;i++){
        m-=k*minn[i];
        k++;
        if(m<=0){
            cnt=minn[i+1];
            break;
        }
    }
    if(cnt==0) cout<<k+1;
    else cout<<k;
    return 0;
}
