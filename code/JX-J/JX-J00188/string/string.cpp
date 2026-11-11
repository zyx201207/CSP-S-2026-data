#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
string m,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>m;
        for(long long j=0;j<a;j++){
            s+=m;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}