#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
int main(){
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    for(long long i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}