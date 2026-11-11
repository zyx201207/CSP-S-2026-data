#include<bits/stdc++.h>
using namespace std;
long long ans,n,k[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>k[i]>>c[i];
    for(int i=1,j=n;i<j;){
        long long w=min(k[i],k[j]);
        if(c[i]!=c[j]) ans+=w;
        if(k[i]<k[j]) k[j]-=w,i++;
        else if(k[i]>k[j]) k[i]-=w,j--;
        else i++,j--;
    }
    cout<<ans;
    return 0;
}
