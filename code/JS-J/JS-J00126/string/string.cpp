#include<bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+10;
long long n;
long long a[MAXN];
char ch[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    long long l=1,r=n,ans=0;
    while(l<r){
        if(ch[l]==ch[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[l]==a[r]){
                l++;
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
        }else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }else if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }
        }
        
    }
    cout<<ans<<"\n";
    return 0;
}