#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],max_,t,ans,fs1[200005],fs2[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max_=max(max_,a[i]);
    }
    if(m==1){
        cout<<max_<<endl;
    }
    else{
        cout<<n-m;
    }
    return 0;
}
