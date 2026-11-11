#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    long long n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int r=0,l=n-1;
    while(r!=l){
        if(a[r]==0){
            r++;
            if(r>=l){
                break;
            }
        }
        if(a[l]==0){
            l--;
        }
        int sum=min(a[r],a[l]);
        if(c[r]!=c[l]){
            ans+=sum;
        }
        a[r]-=sum;
        a[l]-=sum;
    }
    cout<<ans;
    return 0;
}
