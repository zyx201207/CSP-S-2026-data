#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        string c;
        cin>>c;
        for(int j=1;j<=a[i];j++) s+=c;
    }
    if(s.size()%2==1){
        long long l=0,r=s.size()-1;
        long long mid=(l+r)/2+1;
        char d[mid+5],e[mid+5];
        for(long long i=l;i<mid;i++) d[i+1]=s[i];
        for(long long i=r;i>=mid;i--) e[r-i+1]=s[i];
        for(long long i=1;i<mid;i++) if(d[i]!=e[i]) ans++;
    }
    else{
        long long l=0,r=s.size()-1;
        char x[s.size()/2+5],y[s.size()/2+5];
        for(long long i=l;i<s.size()/2;i++) x[i+1]=s[i];
        for(long long i=r;i>=s.size()/2;i--) y[r-i+1]=s[i];
        for(long long i=1;i<s.size()/2;i++) if(x[i]!=y[i]) ans++;
    }
    cout<<ans;
    return 0;
}
