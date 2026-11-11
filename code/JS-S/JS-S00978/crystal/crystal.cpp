#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=0,d,minn=1e13;
long long a[500050],s[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s[0]=1e13;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s[i-1]=a[i]-a[i-1];
        if(s[i-1]<minn)minn=s[i-1],d=i-1;
    }
    while(m>0){
        m=m-s[d]*(ans+1);
        ans++;
        s[d]=1e13;
        if(s[d+1]>s[d-1])d--;
        else d++;
    }
    cout<<ans+1;
    return 0;
}
