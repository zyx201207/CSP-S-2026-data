#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,L=0,ans=0;
int a[200005],s[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        s[i]=a[i]+s[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            int n1=s[j-1]+1,n2=s[j],n3=L-s[i-1],n4=L-s[i]+1;
            if(n2<n4){
                break;
            }
            if(n1>n3){
                continue;
            }
            if(n1<=n4){
                if(n3<=n2){
                    if(c[j]!=c[i]){
                        ans+=n3-n4+1;
                    }
                }
                if(n2<n3){
                    if(c[j]!=c[i]){
                        ans+=n2-n4+1;
                    }
                }
            }
            if(n4<n1){
                if(n3<=n2){
                    if(c[j]!=c[i]){
                        ans+=n3-n1+1;
                    }
                }
                if(n2<n3){
                    if(c[j]!=c[i]){
                        ans+=n2-n1+1;
                    }
                }
            }
        }
        if(s[i]>=L/2)    break;
    }
    cout<<ans;
    return 0;
}
