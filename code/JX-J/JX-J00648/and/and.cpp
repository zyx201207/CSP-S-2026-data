#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
int a[206778],b[207891];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }for(int i=1;i<=n;i++){
        int c=0;
        for(int j=1;j<=n;j++){
            if(b[i]^a[j]>b[i]){
                c++;
                b[i]=b[i]^a[j];
            }if(c==k){
                break;
            }
        }
    }for(int i=1;i<=n;i++){
        if(ans<b[i]){
            ans=b[i];
        }
    }cout<<ans;
    return 0;
}
