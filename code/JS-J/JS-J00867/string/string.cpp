#include<bits/stdc++.h>
using namespace std;
long long n,b,c=0;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b>>a;
        for(int j=0;j<b;j++){
            s+=a;
        }
    }
    for(long long i=0;i<s.size()-i-1;++i){
        if(s[i]!=s[s.size()-1-i]){
            c++;
        }
    }
    cout<<c;
    return 0;
}
//need better!!!
