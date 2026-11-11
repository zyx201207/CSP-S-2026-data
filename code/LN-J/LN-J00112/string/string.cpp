#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
long long ans=0;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    long long l=s.length();
    long long i=0;
    long long j=l-1;
    while(true){
        if(j<i){
            break;
        }
        if(s[i]!=s[j]){
            ans++;
        }
        i++;
        j--;
    }
    cout<<ans;
    return 0;
}
