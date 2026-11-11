#include <bits/stdc++.h>
using namespace std;
int f(string s){
    int cnt = 0;
    for(long long i = 0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j])
            cnt++;
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005];
    char c;
    string s = "";
    cin>>n;
    for(long long i = 1;i<=n;i++){
        cin>>a[i]>>c;
        for(long long j = 1;j<=a[i];j++){
            s = s+c;
        }
    }
    cout<<f(s)<<'\n';
    return 0;
}
