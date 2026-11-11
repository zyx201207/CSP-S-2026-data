#include<bits/stdc++.h>
using namespace std;
long long a[200001]={};
char c[200001]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long ans=0;
    long long l=1,r=n;
    while(1){
        if(n%2==0){
            if(l>=r){
                break;
            }
        }
        else{
            if(l>=r){
                break;
            }
        }
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
            long long ls=min(a[l],a[r]);
            a[l]-=ls;
            a[r]-=ls;
            if(a[r]==0){
                r--;
            }
            if(a[l]==0){
                l++;
            }
            continue;
        }
        else{
            int ls=min(a[l],a[r]);
            a[l]-=ls;
            a[r]-=ls;
            if(a[r]==0){
                r--;
            }
            if(a[l]==0){
                l++;
            }
            continue;
        }

    }
    cout<<ans;
    return 0;
}
