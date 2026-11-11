#include<bits/stdc++.h>
using namespace std;
int n,c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        string a;
        cin>>x>>a;
        for(long long j=1;j<=x;j++){
            s=s+a;
        }
    }
    for(long long i=0;i<s.size()/2+1;i++){
        if(s[i]!=s[s.size()-i-1]){
            s[s.size()-i-1]=s[i];
            c++;

        }
    }
    cout<<c;
    return 0;
}
