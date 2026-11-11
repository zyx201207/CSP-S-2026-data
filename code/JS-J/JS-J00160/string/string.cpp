#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int bi=n,i=1;
    while(i<bi){
        long long x=min(a[i],a[bi]);
        if(a[i]==x)a[bi]-=a[i],a[i]=0;
        else a[i]-=a[bi],a[bi]=0;
        if(b[i]!=b[bi])cnt+=x;
        if(a[i]==0)i++;
        if(a[bi]==0)bi--;
    }
    cout<<cnt;
    return 0;
}
