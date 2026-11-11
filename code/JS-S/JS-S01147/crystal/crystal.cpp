//
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long a[500007];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long mid,k;
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            mid=(i+n)/2;
            break;
        }
    }
    long long as=a[mid],ans=0;
    for(int i=mid;i>=1;i--){
        long long cur=as-a[i];
        if(cur<=m){
            a[i]=as;
            m-=cur;
            ans++;
        }
        else break;
    }
    for(int i=mid+1;i<=n;i++){
        long long cur=a[i]-as;
        cur*=ans;
        if(cur<=m){
            ans++;
            as=a[i];
            m-=cur;
        }
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
