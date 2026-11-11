#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long a[N];
char c[N];
string s="";
long long n,sum=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        for(int j=0;j<a[i];j++) s+=c[i];
    }

    if(sum%2==1){
        for(int i=0;i<=s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) ans++;
        }
    }
    else if(sum%2==0){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) ans++;
            else cout<<s[i]<<" "<<s[s.size()-1-i]<<" ";
        }

    }
    cout<<ans;
    return 0;
}
