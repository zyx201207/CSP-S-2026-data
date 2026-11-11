#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
string s,s1;
long long n,ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        int a;
        char ch;
        cin>>a>>ch;
        for(int j=1;j<=a;j++){
            s+=ch;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }
    long long len=s.size();
    for(int i=1;i<=len;i++){
        if(s==s1){
            cout<<ans;
            return 0;
        }
        if(s1[i]!=s[i]){
            ans++;
            s1[i]=s[i];
            s[len-i-1]=s1[len-i-1];
        }
    }
    return 0;
}
