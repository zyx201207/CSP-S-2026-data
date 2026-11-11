#include<bits/stdc++.h>
using namespace std;
int l,r,ans,n,a[200005],b;
char c[200005],s[2000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            b+=1;
            s[b]=c[i];
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    l=0;
    r=b;
    for(int i=1;i<=(b/2)+1;i++){
        if(s[l]!=s[r]){
            ans+=1;
        }
        l+=1;
        r-=1;
    }
    cout<<ans;
}
