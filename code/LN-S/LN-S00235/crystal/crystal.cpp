#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],ans=1;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        b[i]=a[i+1]-a[i];
    }
    int l=1;
    for(int i=0;i<n-1;i++){
        for(int k=i;k<n-1;k++){
            if((b[k]-b[k-1])*l<m){
                l++;
            }
            else{
                ans=max(ans,l);
                l=1;
                break;
            }
            if(k==n-2)l=0;
        }
    }
    cout<<ans;
    return 0;
}
