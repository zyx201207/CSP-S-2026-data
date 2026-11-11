#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,ans;
bool ji;
long long le,da;
struct w{
    int a;
    char c;
}s[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        le += s[i].a;
        if(s[i].a%2==1) ji=!ji;
    }
    l=1,r=n;
    while(l<r){
            if(s[l].a>s[r].a){
                if(s[l].c==s[r].c) ans += s[r].a;
                s[l].a-=s[r].a;
                s[r].a=0;
                --r;
            }else{
                if(s[l].c==s[r].c) ans += s[l].a;
                s[r].a-=s[l].a;
                s[l].a=0;
                l++;
            }
    }
    if(n%2==1){
        ans += s[(n+1)/2].a/2;
    }
    if(ji==true) ans=ans*2+1;
    else ans=ans*2;
    da=(le-ans)/2;
    cout<<da;
    return 0;
}
