#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=2e5+10;
int n;
int a[MAXN];
char c[MAXN];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }

    int ans=0,l=1,i=1,r=n,j=a[n];
    while(l<r){
        int x=a[l]-i+1,y=j;
        if(c[l]!=c[r]) ans+=min(x,y);

        if(x>y){
            i+=y;
            r--; j=a[r];
        }
        else if(x==y){
            l++; i=1;
            r--; j=a[r];
        }
        else{
            l++; i=1;
            j-=x;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
