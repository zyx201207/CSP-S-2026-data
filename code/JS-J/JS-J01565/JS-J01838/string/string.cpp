#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N];
char c[N];
long long nx=0;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        nx+=a[i];
    }
    int x=1,y=n;
    long long k=1;
    while(k<=nx/2){
        long long cnt=min(a[x],a[y]);
        a[x]-=cnt;a[y]-=cnt;
        if(c[x]!=c[y]){
            ans+=cnt;
        }
        if(a[x]==0)x++;
        if(a[y]==0)y--;
        k+=cnt;
    }
    cout<<ans;
    return 0;
}
