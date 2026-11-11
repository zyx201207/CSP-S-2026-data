#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long arr[200002];
char c[200002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i]>>c[i];
    }
    long long l=1,r=n;
    while(l<r){
        if(arr[l]>arr[r]){
            if(c[l]!=c[r])ans+=arr[r];
            arr[l]-=arr[r];
            r--;
        }
        else if(arr[l]==arr[r]){
            if(c[l]!=c[r])ans+=arr[l];
            l++;
            r--;
        }
        else{
            if(c[l]!=c[r])ans+=arr[l];
            arr[r]-=arr[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
