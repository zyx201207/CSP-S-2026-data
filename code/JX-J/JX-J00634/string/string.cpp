#include<bits/stdc++.h>
using namespace std;
long long n;
const long long N=1e6;
long long a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];

    }
    long long ans=0;
    long long r=n;
    for(long long l=1;l<=r;){
            if (l==r){
                break;
            }
            long long flag=min(a[l],a[r]);
            a[l]-=flag;
            a[r]-=flag;
            if(b[l]!=b[r]){
            ans+=flag;
            }
            if(a[l]==0) l++;
            if(a[r]==0) r--;
    }
    cout<<ans;
    return 0;
}
