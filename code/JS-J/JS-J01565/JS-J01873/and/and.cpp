#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2005],ans;
bool A=1;
bool is(long long k){
    while(k!=1){
        if(k%2==0)return 0;
        k=k/2;
    }
    return 1;
}
bool cmp(long long a,long long b){return a>=b;}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!is(a[i]))A=0;
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++)ans=ans&a[i];
        cout<<ans;
        return 0;
    }else if(m==1){
        ans=a[1];
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }else if(A){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }else{
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=1;i<=m;i++)ans=ans&a[i];
        cout<<ans;
    }
    return 0;
}
