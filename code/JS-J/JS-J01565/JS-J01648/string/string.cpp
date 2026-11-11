#include <bits/stdc++.h>
using namespace std;
int n;
int a[200015],sum[200015];
char c[200015];
int dy(int x){
    int mid,l=1,r=n,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(sum[mid]==x){
            return mid;
        }
        else if(sum[mid]<x){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    int num=0;
    int i=1;
    while(i<=sum[n]/2){
        int j=sum[n]+1-i;
        int k1=dy(i),k2=dy(j);
        if(c[k1]!=c[k2])num++;
        i+=min(a[k1],a[k2]);
    }
    cout<<num;
    return 0;
}
