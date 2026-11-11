#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    string s;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--){
            s=s+c;
        }
    }
    long long len=s.length()-1;
    long long len1=len;
    long long cnt=0;
    for(long long i=0;i<=len/2;i++){
        if(s[i]!=s[len1--]) cnt++;
    }
    cout<<cnt;
    return 0;
}
