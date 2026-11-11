#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char c[200010];
int main(){
    ios::sync_with_stdio(NULL);
    cout.tie(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n,ans=0;
    while(l<r){
        long long mn=min(a[l],a[r]);
        if(c[l]==c[r]){
            a[l]-=mn;
            a[r]-=mn;
        }else{
            ans+=mn;
            a[l]-=mn;
            a[r]-=mn;
        }
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}