#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt=0,num1=0,num2=0,ans=0,s1[400005],s2[200005];
char c[200005],d[200005];
struct ss{
    long long fi;
    bool se;
};
ss v[400005];
bool cmp(ss a,ss b){
    return a.fi<b.fi;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for (int i=1;i<=n;i++){
        d[i]=c[n-i+1];
        s1[i]=s1[i-1]+a[i];
        s2[i]=s2[i-1]+a[n-i+1];
    }
    for (int i=1;i<=n;i++){
        v[2*i-1].fi=s1[i];
        v[2*i-1].se=(c[i]!=c[n-i+1]);
        v[2*i].fi=s2[i];
        v[2*i].se=(c[i]!=c[n-i+1]);
    }
    sort(v,v+2*n,cmp);
    for (int i=1;i<n;i++){
        ans+=(v[i].fi-v[i-1].fi)*(v[i].se);
    }
    cout<<ans;
    return 0;
}
