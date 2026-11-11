#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
long long n,ans,l,r;
long long a[N];
char ch[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;++i){
        cin>>a[i]>>ch[i];
    }
    l=1,r=n;
    while(l<=r){
       // cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" "<<ch[l]<<" "<<ch[r];
        if(ch[l]==ch[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[r]>a[l]){
                a[r]-=a[l];
                l++;
            }else{
                r--;
                l++;
            }
        }else{
            ans+=min(a[l],a[r]);
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[r]>a[l]){

                a[r]-=a[l];
                l++;
            }else{
                r--;
                l++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
