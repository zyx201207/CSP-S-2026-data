#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string ans = "";
    for(long long i = 1; i <= n; i++){
        long long b;
        cin>>b;
        char t;
        cin>>t;
        for(int j = 1; j <= b; j++){
            ans+=t;
        }
    }
    long long ns = ans.size();
    long long cnt = 0;
    for(long long i = 0; i < ns/2; i++){
        if(ans[i] != ans[ns-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
