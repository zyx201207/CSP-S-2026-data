#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
long long ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int i=1,j=n;
    while(j>i){
        int b=min(a[i],a[j]);
        if(c[i]!=c[j]){
            a[i]-=b;
            a[j]-=b;
            ans+=b;
            if(a[i]<=0) i++;
            if(a[j]<=0) j--;
        }
        else {
            a[i]-=b;
            a[j]-=b;
            if(a[i]<=0) i++;
            if(a[j]<=0) j--;
        }
    }
    cout<<ans;
    return 0;
}
