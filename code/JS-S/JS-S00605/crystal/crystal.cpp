#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans=0;
long long m1;
int f(int x){
    int cnt=0,m=m1;
    for(int i=x;i<n;i++){
        if(m>=(cnt+1)*(a[i+1]-a[i])){
            cnt++;
            m-=cnt*((a[i+1]-a[i]));
        }
        else{
            return cnt+1;
        }
    }
    return cnt+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+1);
    for(int i=1;i<=n;i++){
        ans=max(ans,f(i));
    }
    cout<<ans;
    return 0;
}
