#include<bits/stdc++.h>
using namespace std;
bool hwq(string b){
    long long lend=b.size()-1;
    bool h=0;
    for(int i=0;i<b.size();i++){
        if(b[i]!=b[lend-i]){
            return 0;
        }
    }
    return 1;
}
long long n,a,cnt;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    if(hwq(s)==1){
        cout<<0;
        return 0;
    }else{
        long long l=s.size()-1;
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[l-i]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
