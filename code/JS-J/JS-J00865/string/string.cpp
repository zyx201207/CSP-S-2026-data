#include<bits/stdc++.h>
using namespace std;
long long n,a;
string s="",c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt/2<<endl;
    return 0;
}
