#include<bits/stdc++.h>
using namespace std;
const int mxN=5e5+5;
int n,arr[mxN],b[mxN],mx;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    stable_sort(arr+1,arr+1+n);
    for(int i=n;i>=1;i--){
        int ans=1,l=m;
        memset(b,0,sizeof(b));
        for(int j=i-1;j>=1;j--){
            b[j]=arr[i]-arr[j];
        }
        for(int j=i-1;j>=1;j--){
            if((l-b[j])>=0){
                ans++;
                l-=b[j];
            }else{
                break;
            }
        }
        mx=max(ans,mx);
    }
    cout<<mx;
    return 0;
}
