#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long a[200010];
    char b[200010];
    string s;
    long long cnt;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            cnt++;
        }
        //cout<<s[i]<<"+"<<s[s.length()-i-1]<<" ";
    }
    //cout<<s.length()<<" ";
    cout<<cnt;
    return 0;
}
