#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200001];
long long ans;
int zh(long long x,long long y,long long s){
    if(y==m){
        ans=max(ans,s);
        return 0;
    }
    for(int i=x+1;i<=n;i++){
        zh(i,y+1,(s&a[i]));
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        zh(i,1,a[i]);
    }
    cout<<ans;
    return 0;
}

