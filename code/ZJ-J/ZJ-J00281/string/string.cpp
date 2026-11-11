#include "bits/stdc++.h"
using namespace std;
#define int long long 

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int num=0;
		char c;
        cin>>num>>c;
        while(num--){
            s+=c;
        }
    }
    reverse(s.begin(),s.end());
    string s2=s;
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i] != s2[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0 ;
}
