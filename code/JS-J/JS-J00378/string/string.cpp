#include<bits/stdc++.h>
using namespace std ;
#define int long long
int n;string s;int cnt;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int x;
        string c;
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s+=c;
        }
    }
       for(int l=0,r=s.size()-1;l<r;l++,r--){
        if(s[l]!=s[r]) cnt++;
    }
    cout<<cnt;
    return 0;
}
