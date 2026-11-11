#include<bits/stdc++.h>
using namespace std;
long long n;
const long long maxn=2e5+5;
long long op[maxn];
char a[maxn];
long long ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>op[i]>>a[i];
        for(long long j=1;j<=op[i];j++) s+=a[i];
    }
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
