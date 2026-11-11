#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int arr[1000000];
int su[1000000];
signed main(){
    int*sum=su+1;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        sum[i]=s;
    }

    int ans=1;
    for(int i=0;i<n;i++){
        int l=0,r=i;
        while(l!=(r+l)/2){
            if((i-(r+l)/2+1)*arr[i]-(sum[i]-sum[(r+l)/2-1])==m){
                r=(r+l)/2-1;
                l=r;
                break;
            }
            if((i-(r+l)/2+1)*arr[i]-(sum[i]-sum[(r+l)/2-1])>m){
                l=(r+l)/2;
            }else{
                r=(r+l)/2;
            }
            //cout<<l<<' '<<r<<' '<<i<<'\n';
        }
        int tmp=l;
        if((i-l+1)*arr[i]-(sum[i]-sum[l-1])>m){
            tmp=r;
        }
        if(ans<i-tmp+1)ans=i-tmp+1;
    }
    cout<<ans;
    return 0;
}