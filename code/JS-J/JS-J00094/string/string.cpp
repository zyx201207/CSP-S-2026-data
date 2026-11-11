#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long m=0;
int main(){
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
        m+=a[i];
    }
    long long ans=0;
    long long l=0,r=n-1;
    while(l<=r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
            if(a[l]>a[r]){
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else {
                l++;
                a[r]-=a[l];
            }
        }
        else{
            l++;r--;
        }
    }
    cout<<ans;
    return 0;
}
