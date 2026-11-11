#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        long long l;char c;
        cin>>l>>c;
        sum+=l;
        for(long long j = 1;j <= l;j++){
            s+=c;
        }
    }
    for(long long i = 0;i <= (sum-1)/2;i++){
        if(s[i]!=s[sum-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
