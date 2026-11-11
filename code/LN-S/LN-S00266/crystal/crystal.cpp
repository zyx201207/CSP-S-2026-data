#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int l=1,r=n;
    long long bi=0,ans=0;
    int mid=0;
    int lmid=0;
    bool flag=1;
    while(l<=r){
        bi=0;
        lmid=mid;
        mid=(l+r)>>1;
        for(int i=1;i<mid;i++){
            bi+=a[mid]-a[i];
        }
        ans=bi;
        for(int i=2;i+mid-1<=n;i++){
            bi-=(a[i+mid-2]-a[i-1]);
            bi+=(mid-1)*b[i+mid-1];
            ans=min(ans,bi);
        }
        if(l==r) break;
        if(ans==m){
            cout<<mid<<endl;
            return 0;
        }else if(ans<m){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(ans<=m){
        cout<<mid<<endl;
    }else if(ans>m){
        cout<<lmid<<endl;
    }
    return 0;
}
