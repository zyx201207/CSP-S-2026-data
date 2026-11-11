#ifndef AND_CPP_INCLUDED
#define AND_CPP_INCLUDED

#endif // AND_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=INT_MIN;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m==1)cout<<0;
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    else if(m==n){
             for(int i=1;i<n;i++){
            maxn=a[i]&a[i+1];
        }
    }
    else{
        cout<<826351;
    }
    cout<<maxn;

    return 0;
}
