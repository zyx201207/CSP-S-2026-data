#include<bits/stdc++.h>
using namespace std;
int n,t;
long long a[200010];
char c[200010];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int j=1,k=n;
    while(j<=k){
        t=min(a[j],a[k]);
        if(c[j]!=c[k]){
            ans+=t;
        }
        if(a[j]==t){
            j++;
            a[k]-=t;
        }
        else{
            k--;
            a[j]-=t;
        }
    }
    cout<<ans<<endl;
    return 0;
}
