#include<bits/stdc++.h>
using namespace std;
long long a[200001],l=1,r,p=1,q,ans;
int n;
char c[200001];
struct tx{
     long long begin;
     long long end;
     char op;
}f[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        r+=a[i];
        f[i].begin=f[i-1].end+1;
        f[i].end=f[i].begin+a[i]-1;
        f[i].op=c[i];
    }
    q=n;
    while(l<=r&&p<=q){
        if(a[p]>a[q]){
            if(f[p].op!=f[q].op) ans=ans+r-f[q].begin+1;
            a[p]-=a[q];
            l+=a[q];
            q--;
            r=f[q].end;
        }
        else if(a[p]<a[q]){
            if(f[p].op!=f[q].op) ans=ans+f[p].end-l+1;
            a[q]-=a[p];
            r-=a[p];
            p++;
            l=f[p].begin;
        }
        else{
            if(f[p].op!=f[q].op) ans+=a[p];
            l+=a[p];
            r-=a[p];
            p++;
            q--;
        }
    }
    cout<<ans;
    return 0;
}
