#include <bits/stdc++.h>
int n,m;
long long minn,maxn,mid;
using namespace std;
long long a[200010];
/*long long wx(){
    long long maxnn=0;
    long long l=1,r=n;
    while(l<r){
        long long mid=(l+r)/2;
        if(a[mid]>maxnn) maxnn=a[mid];
        l=mid+1;
    }
    return maxnn;
}

*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long maxnn=0;

    while(m!=0){
        long long l=1,r=n;
        while(l<r){
            mid=(l+r)/2;
            if(a[mid]>=maxnn){
                maxn=mid;
                maxnn=a[mid];
            }
            l=mid+1;
        }
        if(m-1!=0){
            a[maxn]=0;
            maxnn=0;
            m-=1;
        }else m-=1;
    }
    cout<<maxnn;

    return 0;
}
