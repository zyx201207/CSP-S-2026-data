#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long arr[500005];
long long qz[500005];
// from l all to r
long long getprice(int l,int r){
    return arr[r]*(r-l+1)-(qz[r]-qz[l-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    qz[0]=0;
    for(int i=1;i<=n;i++){
        qz[i]=qz[i-1]+arr[i];
    }
    //cout<<getprice(1,4);
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=n,temp=0;
        while(l<=r){
            int mid=(l+r)>>1;
            long long p=getprice(i,mid);
            if(p>m){
                r=mid-1;
            }else if(p<=m){
                temp=max(temp,mid-i+1);
                l=mid+1;
            }
        }
        ans=max(ans,temp);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
