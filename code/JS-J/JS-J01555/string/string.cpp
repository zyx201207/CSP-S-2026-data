#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt=0;
char c[200005];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        while(a[i]--){
            s+=c[i];
        }
    }
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
