#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],ans,lens;
char c[N];
char f(long long x){
    int i=1;
    while(x>a[i]){
        x-=a[i];
        i++;
    }
    return c[i];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        lens+=a[i];
    }
    for(long long i=1;i<=lens/2;i++){
        if(f(i)!=f(lens-i+1)) ans++;
    }
    cout<<ans;
    return 0;
}
