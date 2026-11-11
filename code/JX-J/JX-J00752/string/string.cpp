#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
    int n;
    long long a;
    string b;
    long long js=0;
    string s;
    long long num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        long long j=0;
        string ls;
        for(;j<a;j++){
            ls+=b;
        }
        s=s+ls;
    }

    for(int k=0;k<=s.size();k++){
        if(s[k]!=s[s.size()-k+1]){
                num++;
        }
        else num-=1;
    }
    cout<<num/2<<s;
    return 0;
}
