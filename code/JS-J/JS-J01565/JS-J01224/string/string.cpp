#include <bits/stdc++.h>
using namespace std;
long long n,num;
string c,s,oc;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num>>c;
        for(long long j=1;j<=num;j++){
            s=s+c;
        }
    }
    long long ss=s.size();
    long long sum=0;
    for(long long i=0;i<ss/2;i++){
        if(s[i]!=s[ss-i-1])sum++;
    }
    cout<<sum;
    return 0;
}
