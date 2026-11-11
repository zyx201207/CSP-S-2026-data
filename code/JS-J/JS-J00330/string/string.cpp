#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long a[n+1],l=1,r=n;
    char b[n+1];
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    while(l<=r){
        if(b[l]!=b[r])ans+=min(a[l],a[r]);
        if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }
        else if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else{
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
