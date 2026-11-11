#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
string l;
long long a[1000000005];
char c[1000000005];
 int main{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        while(a[i]--){
            l+=c[i];
        }
    }
    for(int i=0;i<l.size();i++){
        for(int j=l.size();j>0;j--){
            if(l[i]!=l[j]) ans++;
        }

    }
    cout<<ans;
     return 0;
}
