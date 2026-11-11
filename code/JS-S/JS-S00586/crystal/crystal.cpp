#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ma;
long long m,a[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
        if(a[i]==a[i+1]) continue;
        int l=0,r=i,mid=0;
        while(l<r){
            mid=(l+r)/2;
            long long t=(i-mid)*a[i]-(pre[i]-pre[mid]);
            if(t<=m){
                ma=max(ma,i-mid);
                r=mid;
            }
            else l=mid+1;
        }
    }
    cout<<ma;
    return 0;
}
