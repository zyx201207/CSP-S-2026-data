#include<bits/stdc++.h>
using namespace std;
string s;
long long num;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n ;
    long long a;
    char c;
    for(long long i=0;i<n;i++){
        cin >>a;
        cin >>c;
        num+=a;
        for(long long j=0;j<a;j++){
            s+=c;
        }
    }
    long long b=num/2;
    long long d=s.size();
    for(long long i=0;i<b;i++){
        if(s[i]!=s[d-i-1])ans++;
    }
    cout << ans;
    return 0;
}
