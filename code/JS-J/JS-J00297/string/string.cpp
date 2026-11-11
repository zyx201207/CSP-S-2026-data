#include<bits/stdc++.h>
using namespace std;

int n;
long long l=1,r=0,ans=0;
long long a[200010];
char c[200010];


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        r+=a[i];
    }
    long long lc=1,rc=r;
    long long minc;
    while(l<r){
        minc=min(a[lc],a[rc]);
        if(c[lc]!=c[rc])ans+=minc;
        a[lc]-=minc;
        a[rc]-=minc;
        if(!a[lc])lc++;
        if(!a[rc])rc--;
        l+=minc;
        r-=minc;
    }
    cout<<ans;
    return 0;
}
