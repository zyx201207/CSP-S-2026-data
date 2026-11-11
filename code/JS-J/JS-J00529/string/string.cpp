#include<bits/stdc++.h>
using namespace std;
long long n,n1,ans;
string s;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>n1;
            cin>>a;
        for(int i=1;i<=n1;i++){
            s+=a;
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
