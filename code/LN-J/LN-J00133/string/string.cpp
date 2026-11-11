#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long a[n+1]={0};
    char b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long c=1,d=n,ans=0;
    while(c<d){
        long long temp=min(a[c],a[d]);
        if(b[c]!=b[d]){
            ans+=temp;
        }
        a[c]=a[c]-temp;
        a[d]=a[d]-temp;
        if(a[c]==0) c++;
        if(a[d]==0) d--;
    }
    cout<<ans;
    return 0;
}
