#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
              s+=c;
        }
    }
    string t=s;
    reverse(s.begin(),s.end());
    if(t==s){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            cnt++;
        }
    }
    cout<<cnt/2;

    return 0;
}
