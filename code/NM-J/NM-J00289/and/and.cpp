#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long ans;
void d(long long b,long long c,long long e){
    if(c<=ans) return;
    if(b==0){
        ans=max(ans,c);
        return;
    }
    if(e>n) return;
    d(b-1,(c&a[e]),e+1);
    d(b,c,e+1);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int q=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q=max(q,a[i]);
    }
    if(m==1){
        cout<<q;
        return 0;
    }
    d(m,1073741823,1);
    cout<<ans;
    return 0;
}